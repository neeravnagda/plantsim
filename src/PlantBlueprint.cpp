#include <iostream>
#include <algorithm>
#include <fstream>
#include "include/PlantBlueprint.h"

std::map<std::string, PlantBlueprint*> PlantBlueprint::s_instances;
rTree_t PlantBlueprint::s_rTree;

PlantBlueprint* PlantBlueprint::instance(const std::string _instanceID)
{
		const auto it = s_instances.find(_instanceID);
		//return the instance if it was found
		if (it != s_instances.end())
		{
				return static_cast<PlantBlueprint*>(it->second);
		}
		//If it wasn't found, create a new instance
		PlantBlueprint* blueprint = new PlantBlueprint;
		s_instances[_instanceID] = blueprint;
		return blueprint;
}

void PlantBlueprint::destroy(const std::string _instanceID)
{
		auto it = s_instances.find(_instanceID);
		if (it != s_instances.end())
		{
				delete (*it).second;
				s_instances.erase(it);
		}
}

void PlantBlueprint::destroyAll()
{
		for (auto i : s_instances)
		{
				delete i.second;
		}
		s_instances.clear();
}

PlantBlueprint::PlantBlueprint(){}
PlantBlueprint::~PlantBlueprint(){}

//Set the first line of the file as the axiom
//All successive lines are the production rules
void PlantBlueprint::readGrammarFromFile(const std::string _filePath)
{
		std::ifstream fileIn(_filePath);//Open the file
		std::string line;//Temp string for each line

		//Add the first line as the axiom
		{
				std::getline(fileIn,line);

				//Remove any whitespaces, '=' and ',' to avoid errors
				line.erase(std::remove(line.begin(),line.end(),' '),line.end());
				line.erase(std::remove(line.begin(),line.end(),'='),line.end());
				line.erase(std::remove(line.begin(),line.end(),','),line.end());

				//Convert to a branch if not specified in text file
				if (line.compare(0,1,"[",1)!=0)
				{
						line.insert(0,"[");
						line.append("]");
				}
				m_axiom = line;
		}

		//Add the rules, one line at a time
		while (std::getline(fileIn,line))
		{
				//Remove whitespaces
				//auto lineIterator = std::remove(line.begin(),line.end(),' ');
				line.erase(std::remove(line.begin(),line.end(),' '),line.end());

				//Create variables to add to the container
				std::string predecessorValue;
				std::string successorValue;
				float probabilityValue = 1.0f;

				//Everything from start of line to '=' is the predecessor
				std::size_t predecessorPosition = line.find('=');
				if (predecessorPosition != std::string::npos)
				{
						predecessorValue = line.substr(0,predecessorPosition);

						//Remove any duplicate '=' or ',' values from the string
						predecessorValue.erase(std::remove(predecessorValue.begin(),predecessorValue.end(),'='),
																	 predecessorValue.end());
						predecessorValue.erase(std::remove(predecessorValue.begin(),predecessorValue.end(),','),
																	 predecessorValue.end());
				}
				else continue;

				//Everything from '=' to ',' is the successor
				++predecessorPosition;//Exclude the "=" symbol
				std::size_t successorPosition = line.find(',');
				if (successorPosition != std::string::npos)
				{
						successorValue = line.substr(predecessorPosition, successorPosition - predecessorPosition);
				}
				else
				{
						successorValue = line.substr(predecessorPosition, line.length() - predecessorPosition);
				}

				//Remove any duplicate '=' or ',' values from the string
				successorValue.erase(std::remove(successorValue.begin(),successorValue.end(),'='),
														 successorValue.end());
				successorValue.erase(std::remove(successorValue.begin(),successorValue.end(),','),
														 successorValue.end());

				//Check for error if successor value is empty
				if (successorValue.empty())
						continue;

				if (successorPosition != std::string::npos)
				{
						++successorPosition;
						std::string probabilityText = line.substr(successorPosition, line.length() - successorPosition);
						probabilityValue = std::stof(probabilityText);

						//Check if probability is out of range
						if (probabilityValue > 1.0f)
								probabilityValue = 1.0f;
						else if (probabilityValue < 0.0f)
								probabilityValue = 0.0f;
				}

				//Construct the rule in the container
				m_productionRules.emplace_back(predecessorValue,successorValue,probabilityValue);
		}
}

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>
#include <vector>
#include "Plant.h"
#include "ProductionRule.h"

//----------------------------------------------------------------------------------------------------------------------
/// @file Environment.h
/// @brief this class allows the management of the objects in the Open L-system simulation
/// @author Neerav Nagda
/// @version 0.1
/// @date 18/03/17
/// @class Environment
/// @brief this class contains the environment rtree and a container of the individual plants
//----------------------------------------------------------------------------------------------------------------------

class Environment
{
		public:
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief the constructor for this class
				//----------------------------------------------------------------------------------------------------------------------
				Environment();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief destructor
				//----------------------------------------------------------------------------------------------------------------------
				~Environment();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief calls the update for each plant in the container
				//----------------------------------------------------------------------------------------------------------------------
				void update();

		private:
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief container for plant objects
				//----------------------------------------------------------------------------------------------------------------------
				std::vector<Plant> m_plants;
		//----------------------------------------------------------------------------------------------------------------------
		//L-system members
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief L-system axiom
				/// this will be the same for each newly created plant
				//----------------------------------------------------------------------------------------------------------------------
				std::string m_axiom;
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief container for L-sytem production rules
				/// these will be the same for each plant in the container
				//----------------------------------------------------------------------------------------------------------------------
				std::vector<ProductionRule> m_productionRules;
				//----------------------------------------------------------------------------------------------------------------------
		//----------------------------------------------------------------------------------------------------------------------

		//----------------------------------------------------------------------------------------------------------------------
		//L-system methods
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief read the L-system grammar from a text file
				/// @param [in] file path to text file
				//----------------------------------------------------------------------------------------------------------------------
				void readGrammarFromFile(const std::string _filePath);
		//----------------------------------------------------------------------------------------------------------------------
};

#endif // ENVIRONMENT_H

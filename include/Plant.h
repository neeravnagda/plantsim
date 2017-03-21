#ifndef PLANT_H_
#define PLANT_H_

#include <random>
#include <string>
#include <vector>
#include "Branch.h"
#include "PlantBlueprint.h"
#include "ProductionRule.h"
#include "RTreeTypes.h"

//----------------------------------------------------------------------------------------------------------------------
/// @file Plant.h
/// @brief this class contains the information of one plant in the open L-system simulation
/// @author Neerav Nagda
/// @version 0.1
/// @date 18/03/17
/// @class Plant
/// @brief this class manages the simulation of one plant
//----------------------------------------------------------------------------------------------------------------------

class Plant
{
		public:
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief constructor for the class
				/// @param _environmentKey the environment that contains global plant information
				//----------------------------------------------------------------------------------------------------------------------
				Plant(std::string _blueprint);
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief destructor
				//----------------------------------------------------------------------------------------------------------------------
				~Plant();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief update function to evaluate the open L-system simulation
				/// this expands the L-system, converts the string to tokens, and adds bounding boxes to a R-tree
				/// data flows between these functions to ensure the plant interacts with the environment
				//----------------------------------------------------------------------------------------------------------------------
				void update();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief get function for the L-system string
				/// @return the L-system string
				//----------------------------------------------------------------------------------------------------------------------
				std::string getString() const {return m_string;}

		private:
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief remember what type of plant this is
				//----------------------------------------------------------------------------------------------------------------------
				PlantBlueprint* m_blueprint;
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief static seed for random number generator
				//----------------------------------------------------------------------------------------------------------------------
				static std::random_device s_randomDevice;
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief static mersenne twister algorithm
				//----------------------------------------------------------------------------------------------------------------------
				static std::mt19937 s_numberGenerator;
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief the L-system string
				//----------------------------------------------------------------------------------------------------------------------
				std::string m_string;
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief the current depth of the L-system string expansion
				/// Always initialise to 0
				//----------------------------------------------------------------------------------------------------------------------
				unsigned m_depth = 0;
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief container for branch information
				//----------------------------------------------------------------------------------------------------------------------
				std::vector<Branch> m_branches;

				//----------------------------------------------------------------------------------------------------------------------
				/// @brief use the mersienne twister algorithm with a uniform real distribution to generate a random number
				/// @return random float in the range [0,1]
				//----------------------------------------------------------------------------------------------------------------------
				float genRand();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief expand the string using the L-system rules
				//----------------------------------------------------------------------------------------------------------------------
				void stringRewrite();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief count the number of branches in a given string
				/// @param _string a valid L-system string
				/// @return the number of branches within the string
				//----------------------------------------------------------------------------------------------------------------------
				unsigned countBranches(std::string _string);
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief add to the container m_branches
				/// @param _number the number of new branches to add
				/// @param _position the position in the container
				/// This creates the struct branch in the container with no string member
				//----------------------------------------------------------------------------------------------------------------------
				void addBranches(unsigned _number, unsigned _position);
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief convert the L-system string to branch structs
				/// This adds the string member to each branch struct in the container m_branches
				//----------------------------------------------------------------------------------------------------------------------
				void stringToBranches();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief convert branch structs back to one single string
				//----------------------------------------------------------------------------------------------------------------------
				void branchesToString();
};

#endif // PLANT_H_

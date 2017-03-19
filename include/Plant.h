#ifndef PLANT_H_
#define PLANT_H_

#include <random>
#include <string>
#include <vector>
#include "Branch.h"
#include "ProductionRule.h"

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
				/// @param _axiom the initial string
				/// @param _maxDepth the maximum depth to rewrite the string
				/// @param _productionRules pointer to the production rules
				//----------------------------------------------------------------------------------------------------------------------
				Plant(const std::string _axiom, const int _maxDepth, std::vector<ProductionRule>* _productionRules);
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
		// Get functions
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief get function for the L-system string
				/// @return the L-system string
				//----------------------------------------------------------------------------------------------------------------------
				std::string getString() const {return m_string;}
		//----------------------------------------------------------------------------------------------------------------------

		private:
		//----------------------------------------------------------------------------------------------------------------------
		// Random number generator stuff
				static std::random_device s_randomDevice;
				static std::mt19937 s_numberGenerator;

		//----------------------------------------------------------------------------------------------------------------------
		//----------------------------------------------------------------------------------------------------------------------
		// L-system members
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief the L-system string
				//----------------------------------------------------------------------------------------------------------------------
				std::string m_string;
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief pointer to the production rules as it is the same for all plants
				//----------------------------------------------------------------------------------------------------------------------
				std::vector<ProductionRule> *m_productionRules;
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief the current depth of the L-system string expansion
				/// Always initialise to 0
				//----------------------------------------------------------------------------------------------------------------------
				unsigned m_depth = 0;
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief the maximum depth of the L-system string expansion
				/// this prevents an infinite number of expansions
				//----------------------------------------------------------------------------------------------------------------------
				unsigned m_maxDepth;
		//----------------------------------------------------------------------------------------------------------------------
		//----------------------------------------------------------------------------------------------------------------------
		// Intermediate simulation members
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief container for branch information
				//----------------------------------------------------------------------------------------------------------------------
				std::vector<Branch> m_branches;
		//----------------------------------------------------------------------------------------------------------------------

		//----------------------------------------------------------------------------------------------------------------------
		// L-system methods
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
		//----------------------------------------------------------------------------------------------------------------------
		// Intermediate simulation methods
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
				/// @brief convert the L-system string to branches
				/// This adds the string member to each branch struct in the container m_branches
				//----------------------------------------------------------------------------------------------------------------------
				void stringToBranches();
		//----------------------------------------------------------------------------------------------------------------------
};

#endif // PLANT_H_

#ifndef PRODUCTIONRULE_H_
#define PRODUCTIONRULE_H_

#include <string>

//----------------------------------------------------------------------------------------------------------------------
/// @file ProductionRule.h
/// @brief This struct allows the L-system production rules to be put in a custom container
/// @author Neerav Nagda
/// @version 1.0
/// @date 01/04/17
/// @struct ProductionRule
/// @brief Struct to contain information about the L-system production rules
//----------------------------------------------------------------------------------------------------------------------
typedef struct ProductionRule
{
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The character(s) to be replaced
		//----------------------------------------------------------------------------------------------------------------------
		std::string m_predecessor;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The character(s) to replace
		//----------------------------------------------------------------------------------------------------------------------
		std::string m_successor;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Constructor
		//----------------------------------------------------------------------------------------------------------------------
		ProductionRule(std::string _predecessor, std::string _successor) :
			m_predecessor(_predecessor),
			m_successor(_successor){}
} ProductionRule;

#endif // PRODUCTIONRULE_H_

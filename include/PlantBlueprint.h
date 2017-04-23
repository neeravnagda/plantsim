#ifndef PLANTBLUEPRINT_H_
#define PLANTBLUEPRINT_H_

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ngl/Obj.h>
#include <ngl/ShaderLib.h>
#include "ProductionRule.h"
#include "RTreeTypes.h"

//----------------------------------------------------------------------------------------------------------------------
/// @file PlantBlueprint.h
/// @brief This class contains data required for Plant objects
/// @author Neerav Nagda
/// @version 0.5
/// @date 01/04/17
/// @class PlantBlueprint
/// @brief This class contains data required for Plant objects
//----------------------------------------------------------------------------------------------------------------------
class PlantBlueprint
{
	public:
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Delete copy constructor since this is a multiton class
		//----------------------------------------------------------------------------------------------------------------------
		PlantBlueprint(const PlantBlueprint&) = delete;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Delete copy constructor since this is a multiton class
		//----------------------------------------------------------------------------------------------------------------------
		PlantBlueprint& operator=(const PlantBlueprint&) = delete;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get or create an instance of this class
		/// @param _instanceID The key of the instance to return
		//----------------------------------------------------------------------------------------------------------------------
		static PlantBlueprint* instance(const std::string _instanceID);
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Destroys an instance
		/// @param _instanceID The key of the instance to delete
		//----------------------------------------------------------------------------------------------------------------------
		static void destroy(const std::string _instanceID);
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Destroys all instances
		/// This should be called on program exit
		//----------------------------------------------------------------------------------------------------------------------
		static void destroyAll();
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Initialise the shaders and geometry
		/// Note this can only be performed after a valid GL context has been created
		//----------------------------------------------------------------------------------------------------------------------
		static void init();
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for the R-Tree
		/// @return A reference to the R-Tree
		//----------------------------------------------------------------------------------------------------------------------
		static rTree_t& getRTree(){return s_rTree;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Draw the cylinder
		//----------------------------------------------------------------------------------------------------------------------
		static void drawCylinder();
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Read the L-system grammar from a text file
		/// @param _filePath File path to the text file containing L-system grammar and axiom
		//----------------------------------------------------------------------------------------------------------------------
		void readGrammarFromFile(const std::string _filePath);
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_maxDepth
		/// @param _md New max depth
		//----------------------------------------------------------------------------------------------------------------------
		void setMaxDepth(int _md){m_maxDepth = _md;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_drawAngle
		/// @param _angle New angle to rotate
		//----------------------------------------------------------------------------------------------------------------------
		void setDrawAngle(float _angle){m_drawAngle = _angle;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_drawLength
		/// @param _length New default draw length
		//----------------------------------------------------------------------------------------------------------------------
		void setDrawLength(float _length){m_drawLength = _length;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_rootRadius
		/// @param _radius New initial radius
		//----------------------------------------------------------------------------------------------------------------------
		void setRootRadius(float _radius){m_rootRadius = _radius;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_decayConstant
		/// @param _decayConstant New decay constant
		//----------------------------------------------------------------------------------------------------------------------
		void setDecay(float _decayConstant){m_decayConstant = _decayConstant;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_leavesPerBranch
		/// @param _numLeaves New number of leaves per branch
		//----------------------------------------------------------------------------------------------------------------------
		void setNodesPerBranch(unsigned _numNodes){m_nodesPerBranch = _numNodes;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_maxDeviation
		/// @param _deviation New max deviation for space colonisation
		//----------------------------------------------------------------------------------------------------------------------
		void setMaxDeviation(float _deviation){m_maxDeviation = _deviation;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_axiom
		/// @return Reference of the axiom for the L-system
		//----------------------------------------------------------------------------------------------------------------------
		const std::string& getAxiom() const {return m_axiom;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_maxDepth
		/// @return Reference of the max depth of the L-system
		//----------------------------------------------------------------------------------------------------------------------
		const unsigned& getMaxDepth() const {return m_maxDepth;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_productionRules
		/// @return Reference to the container of Production Rules
		//----------------------------------------------------------------------------------------------------------------------
		const std::vector<ProductionRule>& getProductionRules() const {return m_productionRules;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_drawLength
		/// @return Reference to the draw length
		//----------------------------------------------------------------------------------------------------------------------
		const float& getDrawLength() const {return m_drawLength;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_drawAngle
		/// @return Reference to the draw angle
		//----------------------------------------------------------------------------------------------------------------------
		const float& getDrawAngle() const {return m_drawAngle;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_rootRadius
		/// @return Reference to the initial radius
		//----------------------------------------------------------------------------------------------------------------------
		const float& getRootRadius() const {return m_rootRadius;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_decayConstant
		/// @return The decay constant
		//----------------------------------------------------------------------------------------------------------------------
		const float& getDecayConstant() const {return m_decayConstant;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_leavesPerBranch
		/// @return The number of leaves per branch
		//----------------------------------------------------------------------------------------------------------------------
		const unsigned& getNodesPerBranch() const {return m_nodesPerBranch;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_maxDeviation
		/// @return The maximum deviation for space colonisation
		//----------------------------------------------------------------------------------------------------------------------
		const float& getMaxDeviation() const {return m_maxDeviation;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for s_keys
		/// @return Reference to the keys of the map, i.e. the names of the instances
		/// This is used for the UI
		//----------------------------------------------------------------------------------------------------------------------
		static const std::unordered_set<std::string>& getKeys(){return s_keys;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for the shader name
		/// @return Reference to the shader name
		/// This is needed for draw calls
		//----------------------------------------------------------------------------------------------------------------------
		static const std::string& getShaderName(){return s_shaderProgramName;}

	protected:
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief constructor
		/// Made protected as this is a multiton
		//----------------------------------------------------------------------------------------------------------------------
		PlantBlueprint(){}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief destructor
		/// Made protected as this is a multiton
		//----------------------------------------------------------------------------------------------------------------------
		~PlantBlueprint(){}

	private:
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief A container for the instances of this class
		//----------------------------------------------------------------------------------------------------------------------
		static std::unordered_map<std::string, PlantBlueprint*> s_instances;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief A container for the keys in the map
		/// This is needed by the UI
		//----------------------------------------------------------------------------------------------------------------------
		static std::unordered_set<std::string> s_keys;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Spatial visualisation of the environment
		//----------------------------------------------------------------------------------------------------------------------
		static rTree_t s_rTree;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Handle for the shader name
		//----------------------------------------------------------------------------------------------------------------------
		static std::string s_shaderProgramName;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The cylinder mesh
		//----------------------------------------------------------------------------------------------------------------------
		static std::unique_ptr<ngl::Obj> s_cylinder;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief L-system axiom
		//----------------------------------------------------------------------------------------------------------------------
		std::string m_axiom;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Container for L-sytem production rules
		//----------------------------------------------------------------------------------------------------------------------
		std::vector<ProductionRule> m_productionRules;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The max number of iterations for the L-system string expansion
		//----------------------------------------------------------------------------------------------------------------------
		unsigned m_maxDepth;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The angle to rotate when drawing
		//----------------------------------------------------------------------------------------------------------------------
		float m_drawAngle;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The length of one forward draw command
		//----------------------------------------------------------------------------------------------------------------------
		float m_drawLength;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The initial radius
		//----------------------------------------------------------------------------------------------------------------------
		float m_rootRadius;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The decay constant
		//----------------------------------------------------------------------------------------------------------------------
		float m_decayConstant;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The number of leaves in a branch
		//----------------------------------------------------------------------------------------------------------------------
		unsigned m_nodesPerBranch;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The maximum deviation of nodes for space colonisation
		//----------------------------------------------------------------------------------------------------------------------
		float m_maxDeviation;
};

#endif // PLANTBLUEPRINT_H_

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

//----------------------------------------------------------------------------------------------------------------------
/// @file PlantBlueprint.h
/// @brief This class contains data required for Plant objects
/// @author Neerav Nagda
/// @version 1.0
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
		/// @brief Destroys all instances
		/// This is automatically called on program exit
		//----------------------------------------------------------------------------------------------------------------------
		static void destroyAll();
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Initialise the shaders and geometry
		/// Note this can only be performed after a valid GL context has been created
		//----------------------------------------------------------------------------------------------------------------------
		static void init();
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Draw the cylinder
		//----------------------------------------------------------------------------------------------------------------------
		static void drawCylinder();
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Draw the leaf
		//----------------------------------------------------------------------------------------------------------------------
		static void drawLeaf();
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_axiom
		/// @param _axiom The L-system axiom
		//----------------------------------------------------------------------------------------------------------------------
		void setAxiom(const std::string _axiom);
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
		/// @param _number Number of leaves per branch
		//----------------------------------------------------------------------------------------------------------------------
		void setLeavesPerBranch(unsigned _number){m_leavesPerBranch = _number;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_leavesStartDepth
		/// @param _depth Depth when leaves start to appear
		//----------------------------------------------------------------------------------------------------------------------
		void setLeavesStartDepth(unsigned _depth){m_leavesStartDepth = _depth;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_leafScale
		/// @param _scale Scale of the leaves
		//----------------------------------------------------------------------------------------------------------------------
		void setLeafScale(float _scale){m_leafScale = _scale;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_controlPointsPerBranch
		/// @param _numControlPoints New number of leaves per branch
		//----------------------------------------------------------------------------------------------------------------------
		void setControlPointsPerBranch(unsigned _numControlPoints){m_controlPointsPerBranch = _numControlPoints;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_maxDeviation
		/// @param _deviation New max deviation for space colonisation
		//----------------------------------------------------------------------------------------------------------------------
		void setMaxDeviation(float _deviation){m_maxDeviation = _deviation;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_phototropismScale
		/// @param _scale New scale factor for the phototropism
		//----------------------------------------------------------------------------------------------------------------------
		void setPhototropismScaleFactor(float _scaleFactor){m_phototropismScaleFactor = _scaleFactor;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Set function for m_gravitropismScaleFactor
		/// @param _scale New scale factor for the gravitropism
		//----------------------------------------------------------------------------------------------------------------------
		void setGravitropismScaleFactor(float _scaleFactor){m_gravitropismScaleFactor = _scaleFactor;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_axiom
		/// @return Reference of the axiom for the L-system
		//----------------------------------------------------------------------------------------------------------------------
		const std::string& axiom() const {return m_axiom;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_maxDepth
		/// @return Reference of the max depth of the L-system
		//----------------------------------------------------------------------------------------------------------------------
		const unsigned& maxDepth() const {return m_maxDepth;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_productionRules
		/// @return Reference to the container of Production Rules
		//----------------------------------------------------------------------------------------------------------------------
		const std::vector<ProductionRule>& productionRules() const {return m_productionRules;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_drawLength
		/// @return Reference to the draw length
		//----------------------------------------------------------------------------------------------------------------------
		const float& drawLength() const {return m_drawLength;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_drawAngle
		/// @return Reference to the draw angle
		//----------------------------------------------------------------------------------------------------------------------
		const float& drawAngle() const {return m_drawAngle;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_rootRadius
		/// @return Reference to the initial radius
		//----------------------------------------------------------------------------------------------------------------------
		const float& rootRadius() const {return m_rootRadius;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_decayConstant
		/// @return The decay constant
		//----------------------------------------------------------------------------------------------------------------------
		const float& decayConstant() const {return m_decayConstant;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_leavesPerBranch
		/// @return The number of leaves per branch
		//----------------------------------------------------------------------------------------------------------------------
		const unsigned& leavesPerBranch() const {return m_leavesPerBranch;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_leavesStartDepth
		/// @return The depth when leaves start to appear
		//----------------------------------------------------------------------------------------------------------------------
		const unsigned& leavesStartDepth() const {return m_leavesStartDepth;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_leafScale
		/// @return The scale of the leaves
		//----------------------------------------------------------------------------------------------------------------------
		const float& leafScale() const {return m_leafScale;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_controlPointsPerBranch
		/// @return The number of control points per branch
		//----------------------------------------------------------------------------------------------------------------------
		const unsigned& controlPointsPerBranch() const {return m_controlPointsPerBranch;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_maxDeviation
		/// @return The maximum deviation for space colonisation
		//----------------------------------------------------------------------------------------------------------------------
		const float& maxDeviation() const {return m_maxDeviation;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_phototropismScaleFactor
		/// @return The phototropism scale factor
		//----------------------------------------------------------------------------------------------------------------------
		const float& phototropismScaleFactor() const {return m_phototropismScaleFactor;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for m_gravitropismScaleFactor
		/// @return The gravitropism scale factor
		//----------------------------------------------------------------------------------------------------------------------
		const float& gravitropismScaleFactor() const {return m_gravitropismScaleFactor;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for s_keys
		/// @return Reference to the keys of the map, i.e. the names of the instances
		/// This is used for the UI
		//----------------------------------------------------------------------------------------------------------------------
		static const std::unordered_set<std::string>& keys(){return s_keys;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for the shader name
		/// @return Reference to the shader name
		/// This is needed for draw calls
		//----------------------------------------------------------------------------------------------------------------------
		static const std::string& shaderName(){return s_shaderProgramName;}
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Get function for the sun position
		/// @return Reference to the sun position
		//----------------------------------------------------------------------------------------------------------------------
		static const ngl::Vec3& sunPosition(){return s_sunPosition;}

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
		/// @brief Handle for the shader name
		//----------------------------------------------------------------------------------------------------------------------
		static std::string s_shaderProgramName;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The cylinder mesh
		//----------------------------------------------------------------------------------------------------------------------
		static std::unique_ptr<ngl::Obj> s_cylinder;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Handle for the leaf geometry name
		//----------------------------------------------------------------------------------------------------------------------
		static std::string s_leafGeometryName;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Handle for the leaf geometry texture
		//----------------------------------------------------------------------------------------------------------------------
		static GLuint s_leafGeometryTexture;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The sun position
		/// This value is never changed at runtime, but is used for the plant simulation
		//----------------------------------------------------------------------------------------------------------------------
		static ngl::Vec3 s_sunPosition;
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
		/// @brief The number of leaves per branch
		//----------------------------------------------------------------------------------------------------------------------
		unsigned m_leavesPerBranch;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The depth when leaves start to appear
		//----------------------------------------------------------------------------------------------------------------------
		unsigned m_leavesStartDepth;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The scale for the leaf
		//----------------------------------------------------------------------------------------------------------------------
		float m_leafScale;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The number of control points in a branch
		//----------------------------------------------------------------------------------------------------------------------
		unsigned m_controlPointsPerBranch;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief The maximum deviation of nodes for space colonisation
		//----------------------------------------------------------------------------------------------------------------------
		float m_maxDeviation;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Scale factor for phototropism, i.e. how much it grows towards the sun
		//----------------------------------------------------------------------------------------------------------------------
		float m_phototropismScaleFactor;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Scale factor for gravitropism, i.e. how much it falls due to gravity
		/// This is scaled by the size of the branches, so a branch of size 0.5 will have a gravitropism of 0.5 * gravitropismScaleFactor
		//----------------------------------------------------------------------------------------------------------------------
		float m_gravitropismScaleFactor;
};

#endif // PLANTBLUEPRINT_H_

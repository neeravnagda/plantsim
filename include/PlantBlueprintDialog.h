#ifndef PLANTBLUEPRINTDIALOG_H_
#define PLANTBLUEPRINTDIALOG_H_

#include <array>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPalette>
#include <QString>

//----------------------------------------------------------------------------------------------------------------------
/// @file PlantBlueprintDialog.h
/// @brief this class contains the user interface required to create a new Plant Blueprint object
/// @author Neerav Nagda
/// @version 1.0
/// @date 01/04/17
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
/// @struct Validation
/// @brief Contains enum variables
/// @enum variables
/// @brief Enumarated names for the validation array
//----------------------------------------------------------------------------------------------------------------------
struct PlantBlueprintValidation
{
		enum variables
		{
			BLUEPRINTNAME = 0,
			GRAMMARFILE = 1,
			WOODTEXTURE = 2,
			LEAFTEXTURE = 3,
			COUNT = 4
		};
};
typedef PlantBlueprintValidation::variables ValidationVariables;

		namespace Ui {
		class PlantBlueprintDialog;
		}

//----------------------------------------------------------------------------------------------------------------------
/// @class PlantBlueprintDialog
/// @brief This class manages the UI and UI functions for creating a new PlantBlueprint
//----------------------------------------------------------------------------------------------------------------------
		class PlantBlueprintDialog : public QDialog
		{
				Q_OBJECT

			public:
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Constructor
				/// @param parent The object to parent to
				//----------------------------------------------------------------------------------------------------------------------
				explicit PlantBlueprintDialog(QWidget *parent = 0);
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Destructor
				//----------------------------------------------------------------------------------------------------------------------
				~PlantBlueprintDialog();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Get function for the UI
				/// @return Reference to the UI in this class
				//----------------------------------------------------------------------------------------------------------------------
				const Ui::PlantBlueprintDialog& getUI() {return *m_ui;}
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Create a new instance of the Plant Blueprint
				/// @return Status if a new Plant Blueprint was created
				//----------------------------------------------------------------------------------------------------------------------
				bool createPlantBlueprint();

			public slots:
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Check if the blueprint already exists
				//----------------------------------------------------------------------------------------------------------------------
				void checkBlueprintExists();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Check if the file exists
				//----------------------------------------------------------------------------------------------------------------------
				void checkGrammarFileExists();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Reset text colour to black
				//----------------------------------------------------------------------------------------------------------------------
				void resetGrammarFileTextColour();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Check if the file exists
				//----------------------------------------------------------------------------------------------------------------------
				void checkWoodTextureFileExists();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Reset text colour to black
				//----------------------------------------------------------------------------------------------------------------------
				void resetWoodTextureFileTextColour();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Check if the file exists
				//----------------------------------------------------------------------------------------------------------------------
				void checkLeafTextureFileExists();
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Reset text colour to black
				//----------------------------------------------------------------------------------------------------------------------
				void resetLeafTextureFileTextColour();


			private:
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief UI for this class
				//----------------------------------------------------------------------------------------------------------------------
				Ui::PlantBlueprintDialog *m_ui;
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Default colour palette
				/// This resets text colour to black
				//----------------------------------------------------------------------------------------------------------------------
				QPalette c_defaultPalette;
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Array of bools for validation statuses for UI elements
				//----------------------------------------------------------------------------------------------------------------------
				std::array<bool, ValidationVariables::COUNT> m_validationChecks;
				//----------------------------------------------------------------------------------------------------------------------
				/// @brief Check if a file exists
				/// @param _fileName The file to check
				//----------------------------------------------------------------------------------------------------------------------
				bool checkFileExists(QString _fileName);

		};

#endif // PLANTBLUEPRINTDIALOG_H_

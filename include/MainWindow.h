#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>
#include "NGLScene.h"
#include "PlantBlueprintDialog.h"

//----------------------------------------------------------------------------------------------------------------------
/// @file MainWindow.h
/// @brief this class is the main window, containing the NGLScene widget and UI functions
/// @author Neerav Nagda
/// @version 0.1
/// @date 18/03/17
/// @class Plant
/// @brief this class is the main window, containing widgets and UI functions
//----------------------------------------------------------------------------------------------------------------------

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public slots:
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief slot to create a new plant object
		//----------------------------------------------------------------------------------------------------------------------
		void createNewPlant();
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief slot to open the plant blueprint dialog
		//----------------------------------------------------------------------------------------------------------------------
		void openPlantBlueprintDialogFromUI();
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief slot to open the plant blueprint dialog
		//----------------------------------------------------------------------------------------------------------------------
		void openPlantBlueprintDialogFromMenubar();
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief slot to close the plant blueprint dialog
		//----------------------------------------------------------------------------------------------------------------------
		void closePlantBlueprintDialog();
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief slot to create a Plant Blueprint
		/// This calls the PlantBlueprintDialog function with the same name
		/// If the Dialog returns true, close the dialog, else keep it open
		//----------------------------------------------------------------------------------------------------------------------
		void createPlantBlueprint();

	public:
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief constructor
		//----------------------------------------------------------------------------------------------------------------------
		explicit MainWindow(QWidget *parent = 0);
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief destructor
		//----------------------------------------------------------------------------------------------------------------------
		~MainWindow();

	private:
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief the gui
		//----------------------------------------------------------------------------------------------------------------------
		Ui::MainWindow *m_ui;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief OpenGL widget
		//----------------------------------------------------------------------------------------------------------------------
		NGLScene *m_gl;
		//----------------------------------------------------------------------------------------------------------------------
		/// @brief Dialog box to create a new Plant Blueprint Instance
		//----------------------------------------------------------------------------------------------------------------------
		PlantBlueprintDialog *m_plantBlueprintDialog;
};

#endif // MAINWINDOW_H_

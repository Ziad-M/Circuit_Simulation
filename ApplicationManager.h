#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\Input.h"
#include "UI\Output.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Components\Gate.h"
#include "Components\Switch.h"
#include "Components\LED.h"
#include "Components\Connection.h"
#include <vector>
#include <stack>

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Component* CopiedComp;		// Pointer to the last copied/cut component
	Input* pIn;					// Pointer to the Input class
	Output* pOut;				// Pointer to the Output class
	UI* pUI; //pointer to the UI

public:
	ApplicationManager(); //constructor

	// Sets the last copied/cut component
	void SetCopiedComp(Component* pComp);

	// Returns the last copied/cut component
	Component* GetCopiedComp() const;

	// Returns a pointer to Input object
	Input* GetInput();

	// Returns a pointer to Output object
	Output* GetOutput();

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType& acType);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();


	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	// Returns the number of the existing components
	int GetExistingComponentsCount() const;

	// Counts and returns the number of selected components
	int CountSelectedComponents() const;

	// Sets a selection value to all components
	void SetSelectionOfComponents(bool s);

	// Returns a vector of all selected components
	vector<Component*> GetSelectedComponents();

	// Returns a vector of all selected gates
	vector<Gate*> GetSelectedGates();

	// Returns a vector of all connections
	vector<Connection*> GetConnections();

	//Returns a vector of all switches
	vector<Switch*> GetSwitches();

	// Returns a vector of all leds
	vector<LED*> GetLeds();

	// Saves the current circuit
	void Save(ofstream& file);

	// Loads the circuit from the file
	void Load(ifstream& file);

	//destructor
	~ApplicationManager();
};

#endif

#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\AND2.h"
#include <vector>

class AddANDgate2 : public Action
{
private:
	bool mIsLoaded;						// Indicates if the action is loaded from the file or not
	int mX, mY;							// Center point of the gate
	GraphicsInfo mGfxInfo;				// The parameters (coordinates) required to draw the gate
	string mLabel;						// The label of the component
	Gate* mGate;						// Pointer to the added gate
	ActionType mActType;				// The type of the action
	vector<Connection*> mConnections;	// list of all connections to be updated

public:
	/* Constructor */
	AddANDgate2(ApplicationManager* pAppMan, ActionType actType, Data* pLoadedData = NULL);

	/* Reads parameters required for action to execute */
	virtual bool ReadActionParameters();

	/* Executes action */
	virtual bool Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~AddANDgate2();

private:
	/* Returns the message needed to guide the user */
	string GetActionMsg();

	/* Calculates the rectangular bound of the gate */
	void CalculateDimensions();

	/* Adjusts gate's coordinates if it goes out of borders */
	bool AddANDgate2::AdjustGateCoordinates(GraphicsInfo& GfxInfo);

	/* Draws the gate in its current state: faded or invalid */
	void AddANDgate2::DrawGate(bool valid);

	/* Creates the required gate */
	void CreateGate();
};
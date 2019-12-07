#include "ApplicationManager.h"
#include "Actions\AddConnection.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNOTgate1.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddLEDgate1.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddSwitchgate.h"
#include "Actions\AddConnection.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\Exit.h"

using namespace std;

/*Constructor*/
ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	CopiedComp = NULL;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the UI Object & Initialize the UI
	pOut = new Output();
	pIn = pOut->CreateInput();
}
// Sets the last copied/cut component
void ApplicationManager::SetCopiedComp(Component* pComp) {
	CopiedComp = pComp;
}
// Returns the last copied/cut component
Component* ApplicationManager::GetCopiedComp() const {
	return CopiedComp;
}

// Returns a pointer to Input object
Input* ApplicationManager::GetInput() {
	return pIn;
}

// Returns a pointer to Output object
Output* ApplicationManager::GetOutput() {
	return pOut;
}

ActionType ApplicationManager::GetUserAction()
{
	return pIn->GetUserAction(pOut);
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType& ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;

		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;

		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;

		case ADD_INV:
			pAct = new AddNOTgate1(this);
			break;

		case ADD_LED:
			pAct = new AddLEDgate1(this);
			break;

		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;

		case ADD_Switch:
			pAct = new AddSwitchgate(this);
			break;

		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;

		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;



		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(pUI);

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete pUI;

}

/* Saves the current circuit */
void ApplicationManager::Save(ofstream& file) {
	for (int i = 0; i < CompCount; i++) {
		if (!CompList[i]->IsDeleted()) {
			CompList[i]->Save(file);
		}
	}
}

/* Loads the circuit from the file */
void ApplicationManager::Load(ifstream& file) {
	Data compData;
	string compType;
	Action* pAct;

	while (file >> compType, compType != "-1") {
		if (file.eof()) {
			break;
		}

		if (compType == "CONNECTION") {
			file >> compData.Label;
			file >> compData.GfxInfo.x1 >> compData.GfxInfo.y1 >> compData.GfxInfo.x2 >> compData.GfxInfo.y2;
			pAct = new AddConnection(this, &compData);
		}
		else {
			file >> compData.Label;
			file >> compData.GfxInfo.x1 >> compData.GfxInfo.y1;

			if (compType == "AND")
				pAct = new AddANDgate2(this, ADD_GATE_AND, &compData);
			else if (compType == "OR")
				pAct = new AddORgate2(this, ADD_GATE_OR, &compData);
			else if (compType == "NOT")
				pAct = new AddNOTgate1(this, ADD_GATE_NOT, &compData);
			else if (compType == "NAND")
				pAct = new AddNANDgate2(this, ADD_GATE_NAND, &compData);
			else if (compType == "NOR")
				pAct = new AddNORgate2(this, ADD_GATE_NOR, &compData);
			else if (compType == "XOR")
				pAct = new AddXORgate2(this, ADD_GATE_XOR, &compData);
			else if (compType == "XNOR")
				pAct = new AddXNORgate2(this, ADD_GATE_XNOR, &compData);
			else if (compType == "SWITCH")
				pAct = new AddSwitchgate(this, ADD_SWITCH, &compData);
			else if (compType == "LED")
				pAct = new AddLEDgate1(this, ADD_LED, &compData);
		}

		pAct->Execute();
		delete pAct;
	}
}

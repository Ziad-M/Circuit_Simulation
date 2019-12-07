#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "/Circuit_Simulation-master/AddNORgate2.h"
#include "/Circuit_Simulation-master/AddORgate2.h"
#include "/Circuit_Simulation-master/AddNOTgate1.h"
#include "/Circuit_Simulation-master/AddNANDgate2.h"
#include "/Circuit_Simulation-master/AddLEDgate1.h"
#include "/Circuit_Simulation-master/AddXNORgate2.h"
#include "/Circuit_Simulation-master/AddXORgate2.h"
#include "/Circuit_Simulation-master/AddSwitchgate.h"
#include "/Circuit_Simulation-master/ADDCONNECTION.h"


ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
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

void ApplicationManager::ExecuteAction(ActionType ActType)
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
			pAct = new ADDCONNECTION(this);
			//TODO: Create AddConection Action here
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
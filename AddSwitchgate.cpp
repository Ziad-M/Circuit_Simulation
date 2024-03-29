#include "AddSwitchgate.h"
#include "/Circuit_Simulation-master/ApplicationManager.h"

AddSwitchgate::AddSwitchgate(ApplicationManager* pApp) :Action(pApp)
{
}

AddSwitchgate::~AddSwitchgate(void)
{
}

void AddSwitchgate::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("1-Input Switch Gate: Click to add the gate");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the AND2 gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	Switch* pA = new Switch(pGInfo, Switch_FANOUT);
	pManager->AddComponent(pA);
}

void AddSwitchgate::Undo()
{}

void AddSwitchgate::Redo()
{}


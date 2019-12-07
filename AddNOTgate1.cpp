#include "/Circuit_Simulation-master/AddNOTgate1.h"
#include "/Circuit_Simulation-master/ApplicationManager.h"

AddNOTgate1::AddNOTgate1(ApplicationManager* pApp) :Action(pApp)
{
}

AddNOTgate1::~AddNOTgate1(void)
{
}

void AddNOTgate1::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("1-Input NOT Gate: Click to add the gate");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the NOT1 gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	NOT* pA = new NOT(pGInfo, NOT1_FANOUT);
	pManager->AddComponent(pA);
}

void AddNOTgate1::Undo()
{}

void AddNOTgate1::Redo()
{}
#include "AddLEDgate1.h"
#include "/CIE Projects/Circuit_Simulation/ApplicationManager.h"

AddLEDgate1::AddLEDgate1(ApplicationManager* pApp) :Action(pApp)
{
}

AddLEDgate1::~AddLEDgate1(void)
{
}

void AddLEDgate1::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("1-Input LED Gate: Click to add the gate");

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
	LED* pA = new LED(pGInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddLEDgate1::Undo()
{}

void AddLEDgate1::Redo()
{}

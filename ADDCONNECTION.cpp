#include "/Circuit_Simulation-master/ADDCONNECTION.h"
#include "/Circuit_Simulation-master/ApplicationManager.h"



ADDCONNECTION::ADDCONNECTION(ApplicationManager* pApp) :Action(pApp)
{
}

ADDCONNECTION::~ADDCONNECTION(void)
{
}

void ADDCONNECTION::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("connecton");

	

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	
GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the AND2 gate

	pUI->GetPointClicked(x1, y1);
	pUI->GetPointClicked(x2,y2);

	pGInfo->PointsList[0].x = x1;
	pGInfo->PointsList[0].y = y1;
	pGInfo->PointsList[1].x = x2;
	pGInfo->PointsList[1].y = y2;
	
	Connection* pA = new Connection(pGInfo, nullptr, nullptr);
	pManager->AddComponent(pA);
}

void ADDCONNECTION::Undo()
{}

void ADDCONNECTION::Redo()
{}

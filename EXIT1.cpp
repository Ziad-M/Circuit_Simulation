#include"EXIT1.h"
#include"ApplicationManager.h"
EXIT1::EXIT1(ApplicationManager* pApp) :Action(pApp)
{
}

EXIT1::~EXIT1(void)
{
}

void EXIT1::Execute()
{   
	 
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	pUI->ClearDrawingArea();
	
}
void EXIT1::Undo()
{}

void EXIT1::Redo()
{}
#pragma once

#include "/CIE Projects/Circuit_Simulation/Actions/Action.h"
#include "/CIE Projects/Circuit_Simulation/XNOR2.h"

class AddXNORgate2 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddXNORgate2(ApplicationManager* pApp);
	virtual ~AddXNORgate2(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
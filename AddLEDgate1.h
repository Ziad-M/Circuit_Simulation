#pragma once

#include "/Circuit_Simulation-master/Actions/Action.h"
#include "/Circuit_Simulation-master/LED.h"

class AddLEDgate1 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddLEDgate1(ApplicationManager* pApp);
	virtual ~AddLEDgate1(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


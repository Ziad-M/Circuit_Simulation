#pragma once
#include "/CIE Projects/CIE202 - Project Fall 2019 - student/Code Framework/Actions/Action.h"
#include "/CIE Projects/CIE202 - Project Fall 2019 - student/Code Framework/SWITCH.h"


class AddSwitchgate : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddSwitchgate(ApplicationManager* pApp);
	virtual ~AddSwitchgate(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


#pragma once

/*
  Class NOT
  -----------
  represent the 1-input NOT gate
*/


#include "/CIE Projects/Circuit_Simulation/Components/Gate.h"

class NOT :public Gate
{
public:
	NOT(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the NOT gate
	virtual void Draw(UI*);	//Draws 1-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

};
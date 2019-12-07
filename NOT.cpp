#include "NOT.h"

NOT::NOT(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut)
{
}


void NOT::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input NOT gate
void NOT::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawNOT(*m_pGfxInfo);
}

//returns status of outputpin
int NOT::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOT::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOT::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

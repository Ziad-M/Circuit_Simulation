#include "XOR2.h"

XOR2::XOR2(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut)
{
}


void XOR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void XOR2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawXOR2(*m_pGfxInfo);
}

//returns status of outputpin
int XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

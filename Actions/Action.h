#ifndef _ACTION_H
#define _ACTION_H


class ApplicationManager; //forward class declaration


//Base class for all possible actions (abstract class)
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
public:


	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor
	

	//Execute action (code depends on action type)
	virtual void Execute()=0;

	//To undo this action (code depends on action type)
	virtual void Undo()=0;

	//To redo this action (code depends on action type)
	virtual void Redo()=0;




};

#endif
















//pWind

//UI::GetPointClicked(int&, int&);
//{
//	pWind
//}
//int GATE_Width = getGateWidth();
//int GATE_Height = getGateHeight();



//void Select(const GraphicsInfo& r_GfxInfo, bool selected) const
//{
//	string GateImage;
//	if (selected)	//use image in the highlighted case
//		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpg";
//	else
//		GateImage = "Images\\Gates\\Gate_XOR2.jpg";

//	//Draw AND2 Gate at Gfx_Info (1st corner)
//	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
//	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
//};
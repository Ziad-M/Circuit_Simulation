#pragma once

//This header file contains some defenitions to be used all over the application
#define MAX_COMPONENTS	400	// Maximum number of components
#define MAX_CONNECTIONS	20	// Maximum number of input pins that can be connected to any output pin
#define GATES_FANOUT	5
#define SWITCH_FANOUT	5
#define LED_FANOUT		5

class Component;	// Forward class declaration

//All possible actions
enum ActionType
{
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

};

/* Structure holding drawing parameters for components */
struct GraphicsInfo {
	int x1, y1;		// Upper left point
	int x2, y2;		// Lower right point
};
/* Tool bar items */
enum ToolBarItem {
	ITEM_EDIT,
	ITEM_DELETE,
	ITEM_COPY,
	ITEM_CUT,
	ITEM_PASTE,
	ITEM_UNDO,
	ITEM_REDO,
	ITEM_PLAY,
	ITEM_PAUSE,
	ITEM_TRUTHTABLE,
	ITEM_SAVE,
	ITEM_LOAD,
	ITEM_EXIT,

	TOOLS_COUNT,
};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH,
	NCON	//not connected
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT  = 5,	//Default fan out of 2-input AND gate
	NAND2_FANOUT = 5,
	NOR2_FANOUT  = 5,
	OR2_FANOUT   = 5,
	NOT1_FANOUT  = 5,
	Switch_FANOUT = 5,
	LED_FANOUT = 5,
	XNOR_FANOUT = 5,
	XOR_FANOUT = 5,
	CONNECTION_FANOUT=5,
};
#ifndef NULL
#define NULL 0
#endif

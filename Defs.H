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

enum PinType {
	EMPTY,						// Empty pin
	GATE,						// Pin containing gate, switch or led
	HOR_CONNECTION,				// Pin containing horizontal connection
	VER_CONNECTION,				// Pin containing vertical connection
	INTERSECTING_CONNECTIONS	// Pin containing intersecting horizontal and vertical connections
};

//Infromation of what the pin is containing
struct PinInfo {
	PinType Type;
	Component* Comp;

	PinInfo() {
		Type = PinType::EMPTY;
		Comp = NULL;
	}
};

/* Structure holding the index of a pin, used in calculating the path of the connection */
struct Node {
	int x, y;	// The X and Y indices of the pin

	/* Zero-argument constructor */
	Node() {
		x = y = -1;		// Invalid indices as default value
	}

	/* Constructor for ease of access */
	Node(int x, int y) {
		this->x = x;
		this->y = y;
	}

	/* Equality operator for ease of access */
	bool operator==(const Node& rhs) const {
		return (x == rhs.x && y == rhs.y);
	}

	/* Non-equality operator for ease of access */
	bool operator!=(const Node & rhs) const {
		return (x != rhs.x || y != rhs.y);
	}
};

/* Structure holding drawing parameters for components */
struct GraphicsInfo {
	int x1, y1;		// Upper left point
	int x2, y2;		// Lower right point

	/* Zero-argument constructor */
	GraphicsInfo() {
		x1 = x2 = y1 = y2 = 0;
	}

	/* Constructor for ease of access */
	GraphicsInfo(int x1, int y1, int x2, int y2) {
		// To preserve the upper left and lower right points
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);

		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}

	/* Equality operator for ease of access */
	bool operator==(const GraphicsInfo& rhs) const {
		return (x1 == rhs.x1 && y1 == rhs.y1 && x2 == rhs.x2 && y2 == rhs.y2);
	}


/* Structure holding the loaded information needed for creating new components */
struct Data 
{
	string Label;
	GraphicsInfo GfxInfo;
};
#ifndef NULL
#define NULL 0
#endif
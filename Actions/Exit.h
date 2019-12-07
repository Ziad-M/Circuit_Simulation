#pragma once
#include "..\Actions\Action.h"
#include "..\Actions\SaveAction.h"
#include "..\ApplicationManager.h"
#include"..\UI\Dialog.h"
#include <fstream>
#include<iostream>
#include<string>
using namespace std;


class Exit : public Action
{
private:
	ofstream mWrite;

public:
	/* Constructor */
	Exit(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual bool ReadActionParameters();

	/* Executes action */	
	virtual bool Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Exit();
};


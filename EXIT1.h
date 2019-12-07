#pragma once
#include"Actions/Action.h"
class EXIT1 : public Action
{
public:
	EXIT1(ApplicationManager* pApp);
	virtual ~EXIT1(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();



};
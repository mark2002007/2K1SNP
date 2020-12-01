#pragma once
#include "Command.h"

class RemoveAuthorCommand : public Command
{
public:
	RemoveAuthorCommand(Menu* m) { this->m = m; }
	RemoveAuthorCommand() {}
	void ShowInfo() { cout << "RemoveAuthorCommand"; }
	void execute();
};


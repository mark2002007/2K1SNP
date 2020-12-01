#pragma once
#include "Command.h"

class RemoveEmployeeCommand : public Command
{
public:
	RemoveEmployeeCommand(Menu* m) { this->m = m; }
	RemoveEmployeeCommand() {}
	void ShowInfo() { cout << "RemoveEmployeeCommand"; }
	void execute();
};

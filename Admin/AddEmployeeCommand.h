#pragma once
#include "Command.h"

class AddEmployeeCommand : public Command
{
public:
	AddEmployeeCommand(Menu* m) { this->m = m; }
	AddEmployeeCommand() {}
	void ShowInfo() { cout << "AddEmployeeCommand"; }
	void execute();
};
#pragma once
#include "Command.h"

class AddCustomerCommand : public Command
{
public:
	AddCustomerCommand(Menu* m) { this->m = m; }
	AddCustomerCommand() {}
	void ShowInfo() { cout << "AddCustomerCommand"; }
	void execute();
};

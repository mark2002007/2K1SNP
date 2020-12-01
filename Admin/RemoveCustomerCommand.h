#pragma once
#include "Command.h"

class RemoveCustomerCommand : public Command
{
public:
	RemoveCustomerCommand(Menu* m) { this->m = m; }
	RemoveCustomerCommand() {}
	void ShowInfo() { cout << "RemoveCustomerCommand"; }
	void execute();
};



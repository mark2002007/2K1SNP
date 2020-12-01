#pragma once
#include "Command.h"

class AddAuthorCommand : public Command
{
public:
	AddAuthorCommand(Menu* m) { this->m = m; }
	AddAuthorCommand() {}
	void ShowInfo() { cout << "AddAuthorCommand"; }
	void execute();
};

#pragma once
#include "Command.h"

class RemoveBookCommand : public Command
{
public:
	RemoveBookCommand(Menu* m) { this->m = m; }
	RemoveBookCommand() {}
	void ShowInfo() { cout << "RemoveBookCommand"; }
	void execute();
};
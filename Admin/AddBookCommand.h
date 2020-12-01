#pragma once
#include "Command.h"

class AddBookCommand : public Command
{
public:
	AddBookCommand(Menu* m) { this->m = m; }
	AddBookCommand() {}
	void ShowInfo() { cout << "AddBookCommand"; }
	void execute();
};
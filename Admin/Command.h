#pragma once
#include <iostream>
#include<fstream>
using namespace std;

class Menu;

class Command {
protected:
	Menu* m;
public:
	virtual void ShowInfo() = 0;
	virtual void execute() = 0;
};
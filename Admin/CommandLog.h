#pragma once
#include <iostream>
#include "Command.h"
#include <vector>
using namespace std;

class CommandLog {
private:
	static CommandLog instance;
	vector<Command*> command_log;
	//Lock
	CommandLog() {};
	CommandLog(const CommandLog&) = delete;
	CommandLog& operator=(const CommandLog&) = delete;
public:
	void DoLast();
	void ShowLog();
	void Log(Command* com);
	static CommandLog& GetInstance();
};
#include "CommandLog.h"

void CommandLog::DoLast()
{
	if (command_log.size() != 0) 
		command_log[command_log.size() - 1]->execute();
	else {
		system("cls");
		cout << "Command Log is empty..." << endl;
		system("pause");
	}
}

void CommandLog::ShowLog()
{
	for (int i = 0; i < command_log.size(); i++) {
		command_log[i]->ShowInfo();
		if (i < command_log.size() - 1) cout << ", ";
	}
	cout << endl;
}

void CommandLog::Log(Command* com)
{
	command_log.push_back(com);
}

CommandLog& CommandLog::GetInstance()
{
	return instance;
}
CommandLog CommandLog::instance;
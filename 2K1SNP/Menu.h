#include <iostream>
#include "PersonBase.h"
using namespace std;

#ifndef MENU_H
#define MENU_H

class Menu {
private:
	string pointer;
	int pPos = 1;
	string list_ind;
	string title;
	/*AuthorBase* ab;*/
	PersonBase* pb;
	BookBase* bb;

public:
	//ctr
	Menu(string = "", string = "", string = "<", PersonBase & = *(new PersonBase(10)), BookBase & = *(new BookBase(10)));
	//Add/Remove
	void AddAuthor();
	void AddCustomer();
	void AddEmployee();
	void AddBook();

	void RemoveAuthor();
	void RemoveCustomer();
	void RemoveEmployee();
	//void RemoveBook(); *

	void ShowMenu();
	void ShowAdd();
	void ShowRemove();
	void ShowShow();
	void ShowSettings();
	//Settings Methods
	void ChangeTitle();
	void ChangeIndexation();
	void ChangePointer();

	void WriteToFile();
};

#endif // !MENU_H

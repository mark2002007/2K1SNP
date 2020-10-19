#include <iostream>
using namespace std;

#ifndef MENU_H
#define MENU_H

class Menu {
private:
	string pointer;
	int pPos = 1;
	string list_ind;
	string title;
	AuthorBase* ab;
	BookBase* bb;

public:
	//ctr
	Menu(string = "", string = "", string = "<", AuthorBase& = *(new AuthorBase(10)), BookBase& = *(new BookBase(10)));
	//ShowMethods
	void AddAuthor();
	void AddBook();
	void RemoveAuthor();
	//void RemoveBook();

	void ShowMenu();

	void ShowSettings();
	//Settings Methods
	void ChangeTitle();
	void ChangeIndexation();
	void ChangePointer();
};

#endif // !MENU_H

#include <iostream>
#include "AuthorRepository.h"
#include "CustomerRepository.h"
#include "EmployeeRepository.h"
#include "BookRepository.h"
using namespace std;

#ifndef MENU_H
#define MENU_H

class Menu {
private:
	string pointer;
	int pPos = 1;
	string list_ind;
	string title;
	AuthorRepository authorRepository = AuthorRepository(true);
	CustomerRepository customerRepository = CustomerRepository(true);
	EmployeeRepository employeeRepository = EmployeeRepository(true);
	BookRepository bookRepository = BookRepository(&authorRepository, true);
public:
	//ctr
	Menu(string = "", string = "", string = "<");
	//Add/Remove
	void AddAuthor();
	void AddCustomer();
	void AddEmployee();
	void AddBook();

	void RemoveBook();
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

};

#endif // !MENU_H

#pragma once
#include <iostream>
#include "Repository.h"
#include "BookRepository.h"

#include "Author.h"
#include "Customer.h"
#include "Employee.h"

using namespace std;

#ifndef MENU_H
#define MENU_H

class Menu {
private:
	string pointer;
	int pPos = 1;
	string list_ind;
	string title;
	Repository<Author> authorRepository = Repository<Author>(true);
	Repository<Customer> customerRepository = Repository<Customer>(true);
	Repository<Employee> employeeRepository = Repository<Employee>(true);
	BookRepository bookRepository = BookRepository(authorRepository, true);
public:
	//ctr
	Menu(string = "", string = "", string = "<");
	//Add/Remove
	void AddAuthor();
	void AddCustomer();
	void AddEmployee();
	void AddBook();

	void RemoveAuthor();
	void RemoveCustomer();
	void RemoveEmployee();
	void RemoveBook();

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

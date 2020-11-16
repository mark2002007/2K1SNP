#pragma once
#include <iostream>
#include "Repository.h"
#include "BookRepository.h"

#include "Author.h"
#include "Customer.h"
#include "Employee.h"

using namespace std;

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


#pragma once
#include "Repository.h"
#include "BookRepository.h"

#include "Author.h"
#include "Customer.h"
#include "Employee.h"

#include "AddBookCommand.h"
#include "AddAuthorCommand.h"
#include "AddCustomerCommand.h"
#include "AddEmployeeCommand.h"

#include "RemoveBookCommand.h"
#include "RemoveAuthorCommand.h"
#include "RemoveCustomerCommand.h"
#include "RemoveEmployeeCommand.h"

#include "CommandLog.h"


class Menu {
private:
	string pointer;
	int pPos = 1;
	string list_ind;
	string title;
	AddBookCommand a_b_com; AddAuthorCommand a_a_com; AddCustomerCommand a_c_com; AddEmployeeCommand a_e_com;
	RemoveBookCommand r_b_com; RemoveAuthorCommand r_a_com; RemoveCustomerCommand r_c_com; RemoveEmployeeCommand r_e_com;
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
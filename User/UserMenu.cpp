#include<iostream>
#include<fstream>
//#include "../2K1SNP/Author.h"
//#include "../2K1SNP/Customer.h"
//#include "../2K1SNP/Employee.h"
#include "UserMenu.h"
using namespace std;

Menu::Menu(string title, string list_ind, string pointer) {
	this->title = title;
	this->pointer = pointer;
	if (list_ind != "ORDERED" && list_ind != "UNORDERED") throw "List indexation should be ORDERED or UNORDERED!!!";
	this->list_ind = list_ind;
}

//void Menu::AddAuthor() {
//	string fName, mName, lName;
//	int YOB, YOD;
//	system("cls");
//	cout << "\tAdding new Author\n";
//	cout << "First name : "; cin >> fName;
//	cout << "Middle name : "; cin >> mName;
//	cout << "Last name : "; cin >> lName;
//	cout << "Year of birth : "; cin >> YOB;
//	cout << "Year of death : "; cin >> YOD;
//
//	authorRepository.Add(*(new Author(fName, mName, lName, YOB, YOD)));
//}
//
//void Menu::AddCustomer() {
//	string fName, mName, lName;
//	float balance;
//	int purchases;
//	system("cls");
//	cout << "\tAdding new Customer\n";
//	cout << "First name : "; cin >> fName;
//	cout << "Middle name : "; cin >> mName;
//	cout << "Last name : "; cin >> lName;
//	cout << "Balance : "; cin >> balance;
//	cout << "Amount of purchases : "; cin >> purchases;
//
//	customerRepository.Add(*(new Customer(fName, mName, lName, balance, purchases)));
//
//}
//
//void Menu::AddEmployee() {
//	string fName, mName, lName;
//	int salary, rank;
//	system("cls");
//	cout << "\tAdding new Employee\n";
//	cout << "First name : "; cin >> fName;
//	cout << "Middle name : "; cin >> mName;
//	cout << "Last name : "; cin >> lName;
//	cout << "Salary : "; cin >> salary;
//	cout << "Rank : "; cin >> rank;
//
//	employeeRepository.Add(*(new Employee(fName, mName, lName, salary, rank)));
//}
//
//void Menu::AddBook() {
//	char title[50];
//	string ISBN;
//	int publication_year, pages, author_pos;
//	system("cls");
//	cout << "\tAdding new book\n";
//	cout << "Title : ";
//	cin.getline(title, 50);
//	cin.getline(title, 50);
//	cout << "Author (number) : ";
//	cin >> author_pos;
//	cout << "Publication year : ";
//	cin >> publication_year;
//	cout << "Pages : ";
//	cin >> pages;
//	cout << "ISBN : ";
//	cin >> ISBN;
//
//	this->bookRepository.Add(*(new Book(*(authorRepository.Get(author_pos - 1)), title, publication_year, pages, ISBN)));
//}
//
//void Menu::RemoveBook() {
//	system("cls");
//	int pos;
//	cout << "Book to remove (number) : "; cin >> pos;
//	bookRepository.Remove(pos);
//}
//
//void Menu::RemoveAuthor() {
//	system("cls");
//	int pos;
//	cout << "Author to remove (number) : "; cin >> pos;
//	authorRepository.Remove(pos);
//}
//
//void Menu::RemoveCustomer() {
//	system("cls");
//	int pos;
//	cout << "Customer to remove (number) : "; cin >> pos;
//	customerRepository.Remove(pos);
//}
//
//void Menu::RemoveEmployee() {
//	system("cls");
//	int pos;
//	cout << "Employee to remove (number) : "; cin >> pos;
//	employeeRepository.Remove(pos);
//}

void Menu::ShowMenu() {
	//Presets
	bool exit = false;
	int rowN = 3, pPos = 1;
	char user_input;
	while (!exit) {
		//Cout Menu
		system("cls");
		cout << "\t" << title << endl;
		for (int i = 0; i < rowN; i++) {
			if (list_ind == "ORDERED") cout << i + 1 << ". ";
			else if (list_ind == "UNORDERED") cout << "*";
			switch (i + 1) {
			case 1:
				cout << "Show    ";
				break;
			case 2:
				cout << "Settings";
				break;
			case 3:
				cout << "Exit    ";
				break;
			}
			if (i + 1 == pPos) { cout << "  " << pointer; }
			cout << endl;
		}
		cout << "('w '- up,'s' - down,'e' - enter)" << endl;
		//User Input
		cin >> user_input;
		switch (user_input) {
		case 'w':
			if (1 < pPos) pPos--;
			break;
		case 's':
			if (pPos < rowN) pPos++;
			break;
		case 'e':
			switch (pPos) {
			case 1:
				ShowShow();
				break;
			case 2:
				ShowSettings();
				break;
			case 3:
				exit = true;
				break;
			}
			break;
		}
	}
}

//void Menu::ShowAdd() {
//	bool exit = false;
//	int rowN = 5, pPos = 1;
//	char user_input;
//	while (!exit) {
//		//Cout Menu
//		system("cls");
//		cout << "\t" << "Add" << endl;
//		for (int i = 0; i < rowN; i++) {
//			if (list_ind == "ORDERED") cout << i + 1 << ". ";
//			else if (list_ind == "UNORDERED") cout << "*";
//			switch (i + 1) {
//			case 1:
//				cout << "Book    ";
//				break;
//			case 2:
//				cout << "Author  ";
//				break;
//			case 3:
//				cout << "Customer";
//				break;
//			case 4:
//				cout << "Employee";
//				break;
//			case 5:
//				cout << "Exit    ";
//				break;
//			}
//			if (i + 1 == pPos) { cout << "  " << pointer; }
//			cout << endl;
//		}
//		cout << "('w '- up,'s' - down,'e' - enter)" << endl;
//		//User Input
//		cin >> user_input;
//		switch (user_input) {
//		case 'w':
//			if (1 < pPos) pPos--;
//			break;
//		case 's':
//			if (pPos < rowN) pPos++;
//			break;
//		case 'e':
//			switch (pPos) {
//			case 1:
//				AddBook();
//				break;
//			case 2:
//				AddAuthor();
//				break;
//			case 3:
//				AddCustomer();
//				break;
//			case 4:
//				AddEmployee();
//				break;
//			case 5:
//				exit = true;
//				break;
//			}
//			break;
//		}
//	}
//}
//
//void Menu::ShowRemove() {
//	bool exit = false;
//	int rowN = 5, pPos = 1;
//	char user_input;
//	while (!exit) {
//		//Cout Menu
//		system("cls");
//		cout << "\t" << "Remove" << endl;
//		for (int i = 0; i < rowN; i++) {
//			if (list_ind == "ORDERED") cout << i + 1 << ". ";
//			else if (list_ind == "UNORDERED") cout << "*";
//			switch (i + 1) {
//			case 1:
//				cout << "Book    ";
//				break;
//			case 2:
//				cout << "Author  ";
//				break;
//			case 3:
//				cout << "Customer";
//				break;
//			case 4:
//				cout << "Employee";
//				break;
//			case 5:
//				cout << "Exit    ";
//				break;
//			}
//			if (i + 1 == pPos) { cout << "  " << pointer; }
//			cout << endl;
//		}
//		cout << "('w '- up,'s' - down,'e' - enter)" << endl;
//		//User Input
//		cin >> user_input;
//		switch (user_input) {
//		case 'w':
//			if (1 < pPos) pPos--;
//			break;
//		case 's':
//			if (pPos < rowN) pPos++;
//			break;
//		case 'e':
//			switch (pPos) {
//			case 1:
//				RemoveBook();
//				break;
//			case 2:
//				RemoveAuthor();
//				break;
//			case 3:
//				RemoveCustomer();
//				break;
//			case 4:
//				RemoveEmployee();
//				break;
//			case 5:
//				exit = true;
//				break;
//			}
//			break;
//		}
//	}
//}

void Menu::ShowShow() {
	bool exit = false;
	int rowN = 5, pPos = 1;
	char user_input;
	while (!exit) {
		//Cout Menu
		system("cls");
		cout << "\t" << "Show" << endl;
		for (int i = 0; i < rowN; i++) {
			if (list_ind == "ORDERED") cout << i + 1 << ". ";
			else if (list_ind == "UNORDERED") cout << "*";
			switch (i + 1) {
			case 1:
				cout << "Books    ";
				break;
			case 2:
				cout << "Authors  ";
				break;
			case 3:
				cout << "Customers";
				break;
			case 4:
				cout << "Employees";
				break;
			case 5:
				cout << "Exit     ";
				break;
			}
			if (i + 1 == pPos) { cout << "  " << pointer; }
			cout << endl;
		}
		cout << "('w '- up,'s' - down,'e' - enter)" << endl;
		//User Input
		cin >> user_input;
		switch (user_input) {
		case 'w':
			if (1 < pPos) pPos--;
			break;
		case 's':
			if (pPos < rowN) pPos++;
			break;
		case 'e':
			system("cls");
			switch (pPos) {
			case 1:
				bookRepository.Show();
				system("pause");
				break;
			case 2:
				authorRepository.Show();
				system("pause");
				break;
			case 3:
				customerRepository.Show();
				system("pause");
				break;
			case 4:
				employeeRepository.Show();
				system("pause");
				break;
			case 5:
				exit = true;
				break;
			}
			break;
		}
	}
}

void Menu::ShowSettings() {
	//Presets
	bool exit = false;
	int rowN = 4, pPos = 1;
	char user_input;
	while (!exit) {
		//Cout Setttings
		system("cls");
		cout << "\t" << "Settings" << endl;
		for (int i = 0; i < rowN; i++) {
			if (list_ind == "ORDERED") cout << i + 1 << ". ";
			else if (list_ind == "UNORDERED") cout << "*";
			switch (i + 1) {
			case 1:
				cout << "Change title     ";
				break;
			case 2:
				cout << "Change indexation";
				break;
			case 3:
				cout << "Change pointer   ";
				break;
			case 4:
				cout << "Exit             ";
				break;
			}
			if (i + 1 == pPos) { cout << "  " << pointer; }
			cout << endl;
		}
		cout << "('w '- up,'s' - down,'e' - enter)" << endl;
		//User Input
		cin >> user_input;
		switch (user_input) {
		case 'w':
			if (1 < pPos) pPos--;
			break;
		case 's':
			if (pPos < rowN) pPos++;
			break;
		case 'e':
			switch (pPos) {
			case 1:
				ChangeTitle();
				break;
			case 2:
				ChangeIndexation();
				break;
			case 3:
				ChangePointer();
				break;
			case 4:
				exit = true;
			}
			break;
		}
	}
}

void Menu::ChangeTitle() {
	system("cls");
	cout << "Enter title : ";
	cin >> title;
}

void Menu::ChangeIndexation() {
	system("cls");
	cout << "Enter indexation type : ";
	cin >> list_ind;
}

void Menu::ChangePointer() {
	system("cls");
	cout << "Enter pointer : ";
	cin >> pointer;
}
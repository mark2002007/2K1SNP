#include<iostream>
#include<fstream>
#include"Author.h"
#include"Customer.h"
#include "Employee.h"
#include"AuthorBase.h"
#include"BookBase.h"
#include"Menu.h"
using namespace std;

Menu::Menu(string title, string list_ind, string pointer, PersonBase& pb, BookBase& bb) {
	this->title = title;
	this->pointer = pointer;
	if (list_ind != "ORDERED" && list_ind != "UNORDERED") throw "List indexation should be ORDERED or UNORDERED!!!";
	this->list_ind = list_ind;
	this->pb = &pb;
	this->bb = &bb;

	ifstream a_in("Authors.txt");
	ifstream c_in("Customers.txt");
	ifstream e_in("Employees.txt");
	ifstream b_in("Books.txt");

	char fName[50], mName[50], lName[50], A[50], B[50];
	while (a_in >> fName >> mName >> lName >> A >> B) pb.Add(*(new Author(fName, mName, lName, atoi(A), atoi(B))));
	while (c_in >> fName >> mName >> lName >> A >> B) pb.Add(*(new Customer(fName, mName, lName, atoi(A), atof(B))));
	while (e_in >> fName >> mName >> lName >> A >> B) pb.Add(*(new Employee(fName, mName, lName, atoi(A), atoi(B))));
	while (!b_in.eof()) {
		char author_pos[10], title[50], publication_year[10], pages[10], ISBN[15];
		b_in.get(author_pos, 50, ','); b_in.get();
		b_in.get(title, 50, ','); b_in.get();
		b_in.get(publication_year, 50, ','); b_in.get();
		b_in.get(pages, 50, ','); b_in.get();
		b_in.getline(ISBN, 50);
		bb.Add(*(new Book(*((Author*)this->pb->Get("Author", atoi(author_pos))), title, atoi(publication_year), atoi(pages), ISBN)));
	}
	b_in.close();
	e_in.close();
	c_in.close();
	a_in.close();
}

void Menu::AddAuthor() {
	string fName, mName, lName;
	int YOB, YOD;
	system("cls");
	cout << "\tAdding new Author\n";
	cout << "First name : "; cin >> fName;
	cout << "Middle name : "; cin >> mName;
	cout << "Last name : "; cin >> lName;
	cout << "Year of birth : "; cin >> YOB;
	cout << "Year of death : "; cin >> YOD;

	this->pb->Add(*(new Author(fName, mName, lName, YOB, YOD)));
	
	WriteToFile();
}

void Menu::AddCustomer() {
	string fName, mName, lName;
	float balance;
	int purchases;
	system("cls");
	cout << "\tAdding new Customer\n";
	cout << "First name : "; cin >> fName;
	cout << "Middle name : "; cin >> mName;
	cout << "Last name : "; cin >> lName;
	cout << "Balance : "; cin >> balance;
	cout << "Amount of purchases : "; cin >> purchases;

	this->pb->Add(*(new Customer(fName, mName, lName, balance, purchases)));

	WriteToFile();
}

void Menu::AddEmployee() {
	string fName, mName, lName;
	int salary, rank;
	system("cls");
	cout << "\tAdding new Employee\n";
	cout << "First name : "; cin >> fName;
	cout << "Middle name : "; cin >> mName;
	cout << "Last name : "; cin >> lName;
	cout << "Salary : "; cin >> salary;
	cout << "Rank : "; cin >> rank;

	this->pb->Add(*(new Employee(fName, mName, lName, salary, rank)));
	
	WriteToFile();
}

void Menu::AddBook() {
	char title[50];
	string ISBN;
	int publication_year, pages, author_pos;
	system("cls");
	cout << "\tAdding new book\n";
	cout << "Title : ";
	cin.getline(title, 50);
	cin.getline(title, 50);
	cout << "Author (number) : ";
	cin >> author_pos;
	cout << "Publication year : ";
	cin >> publication_year;
	cout << "Pages : ";
	cin >> pages;
	cout << "ISBN : ";
	cin >> ISBN;

	this->bb->Add(*(new Book( *((Author*)pb->Get("Author",author_pos)), title, publication_year, pages, ISBN)));

	ofstream fout("Books.txt", ios::app);
	fout << endl << author_pos << "," << title << "," << publication_year << "," << pages << "," << ISBN;
	fout.close();
}


void Menu::RemoveAuthor() {
	system("cls");
	int pos;
	cout << "Author to remove (number) : "; cin >> pos;
	pb->Remove("Author",pos);
	WriteToFile();
}

void Menu::RemoveCustomer() {
	system("cls");
	int pos;
	cout << "Customer to remove (number) : "; cin >> pos;
	pb->Remove("Customer", pos);
	WriteToFile();
}

void Menu::RemoveEmployee() {
	system("cls");
	int pos;
	cout << "Employee to remove (number) : "; cin >> pos;
	pb->Remove("Customer", pos);
	WriteToFile();
}

void Menu::ShowMenu() {
	//Presets
	bool exit = false;
	int rowN = 5, pPos = 1;
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
				cout << "Add     ";
				break;
			case 2:
				cout << "Remove  ";
				break;
			case 3:
				cout << "Show    ";
				break;
			case 4:
				cout << "Settings";
				break;
			case 5:
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
				ShowAdd();
				break;
			case 2:
				ShowRemove();
				break;
			case 3:
				ShowShow();
				break;
			case 4:
				ShowSettings();
				break;
			case 5:
				exit = true;
				break;
			}
			break;
		}
	}
}

void Menu::ShowAdd() {
	bool exit = false;
	int rowN = 5, pPos = 1;
	char user_input;
	while (!exit) {
		//Cout Menu
		system("cls");
		cout << "\t" << "Add" << endl;
		for (int i = 0; i < rowN; i++) {
			if (list_ind == "ORDERED") cout << i + 1 << ". ";
			else if (list_ind == "UNORDERED") cout << "*";
			switch (i + 1) {
			case 1:
				cout << "Book    ";
				break;
			case 2:
				cout << "Author  ";
				break;
			case 3:
				cout << "Customer";
				break;
			case 4:
				cout << "Employee";
				break;
			case 5:
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
				AddBook();
				break;
			case 2:
				AddAuthor();
				break;
			case 3:
				AddCustomer();
				break;
			case 4:
				AddEmployee();
				break;
			case 5:
				exit = true;
				break;
			}
			break;
		}
	}
}

void Menu::ShowRemove() {
	bool exit = false;
	int rowN = 5, pPos = 1;
	char user_input;
	while (!exit) {
		//Cout Menu
		system("cls");
		cout << "\t" << "Remove" << endl;
		for (int i = 0; i < rowN; i++) {
			if (list_ind == "ORDERED") cout << i + 1 << ". ";
			else if (list_ind == "UNORDERED") cout << "*";
			switch (i + 1) {
			case 1:
				cout << "Book*   ";
				break;
			case 2:
				cout << "Author  ";
				break;
			case 3:
				cout << "Customer";
				break;
			case 4:
				cout << "Employee";
				break;
			case 5:
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
				//RemoveBook();
				break;
			case 2:
				RemoveAuthor();
				break;
			case 3:
				RemoveCustomer();
				break;
			case 4:
				RemoveEmployee();
				break;
			case 5:
				exit = true;
				break;
			}
			break;
		}
	}
}

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
				bb->ShowBooks();
				system("pause");
				break;
			case 2:
				pb->ShowAuthors();
				system("pause");
				break;
			case 3:
				pb->ShowCustomers();
				system("pause");
				break;
			case 4:
				pb->ShowEmployees();
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

void Menu::WriteToFile() {
	ofstream a_out("Authors.txt");
	ofstream c_out("Customers.txt");
	ofstream e_out("Employees.txt");
	int ind = pb->GetLastInd();
	for (int i = 0; i <= ind; i++) {
		if (static_cast<string>(typeid((pb->IndGet(i))[0]).name()) == "class Author") {
			a_out << endl << pb->IndGet(i)->GetFName()
				<< " " << pb->IndGet(i)->GetMName()
				<< " " << pb->IndGet(i)->GetLName()
				<< " " << ((Author*)pb->IndGet(i))->GetYOB()
				<< " " << ((Author*)pb->IndGet(i))->GetYOD();
		}
		else if (static_cast<string>(typeid((pb->IndGet(i))[0]).name()) == "class Customer") {
			c_out << endl << pb->IndGet(i)->GetFName()
				<< " " << pb->IndGet(i)->GetMName()
				<< " " << pb->IndGet(i)->GetLName()
				<< " " << ((Customer*)pb->IndGet(i))->GetBalance()
				<< " " << ((Customer*)pb->IndGet(i))->GetPurchases();
		}
		else if (static_cast<string>(typeid((pb->IndGet(i))[0]).name()) == "class Employee") {
			e_out << endl << pb->IndGet(i)->GetFName()
				<< " " << pb->IndGet(i)->GetMName()
				<< " " << pb->IndGet(i)->GetLName()
				<< " " << ((Employee*)pb->IndGet(i))->GetSalary()
				<< " " << ((Employee*)pb->IndGet(i))->GetRank();
		}
	}
	e_out.close();
	c_out.close();
	a_out.close();
}
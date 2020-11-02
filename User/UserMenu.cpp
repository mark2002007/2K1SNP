#include<iostream>
#include<fstream>
#include "UserMenu.h"
using namespace std;

Menu::Menu(string title, string list_ind, string pointer) {
	this->title = title;
	this->pointer = pointer;
	if (list_ind != "ORDERED" && list_ind != "UNORDERED") throw "List indexation should be ORDERED or UNORDERED!!!";
	this->list_ind = list_ind;
}

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
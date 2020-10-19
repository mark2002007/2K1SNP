#include<iostream>
#include<fstream>
#include"Author.h"
#include"AuthorBase.h"
#include"BookBase.h"
#include"Menu.h"
using namespace std;

Menu::Menu(string title, string list_ind, string pointer, AuthorBase& ab, BookBase& bb) {
	this->title = title;
	this->pointer = pointer;
	if (list_ind != "ORDERED" && list_ind != "UNORDERED") throw "List indexation should be ORDERED or UNORDERED!!!";
	this->list_ind = list_ind;
	this->ab = &ab;
	this->bb = &bb;
	ifstream fin1("Authors.txt");
	ifstream fin2("Books.txt");
	while (!fin1.eof()) {
		char fName[50], mName[50], lName[50], YOB[5], YOD[5];
		fin1.get(fName, 50, ','); fin1.get();
		fin1.get(mName, 50, ','); fin1.get();
		fin1.get(lName, 50, ','); fin1.get();
		fin1.get(YOB, 50, ','); fin1.get();
		fin1.getline(YOD, 50);
		ab.Add(*(new Author(fName,mName,lName,atoi(YOB),atoi(YOD))));
	}
	while (!fin2.eof()) {
		char author_pos[10], title[50], publication_year[10], pages[10], ISBN[15];
		fin2.get(author_pos, 50, ','); fin2.get();
		fin2.get(title, 50, ','); fin2.get();
		fin2.get(publication_year, 50, ','); fin2.get();
		fin2.get(pages, 50, ','); fin2.get();
		fin2.getline(ISBN, 50);
		bb.Add(*(new Book(ab.Get(atoi(author_pos) - 1), title, atoi(publication_year), atoi(pages), ISBN)));
	}
	fin1.close();
	fin2.close();
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

	this->ab->Add(*(new Author(fName, mName, lName, YOB, YOD)));

	ofstream fout("Authors.txt",ios::app);
	fout << endl << fName << "," << lName << "," << mName << "," << YOB << "," << YOD;
	fout.close();
}

void Menu::AddBook() {
	char title[50];
	string ISBN;
	int publication_year, pages, author_pos;
	system("cls");
	cout << "\tAdding new book\n";
	cout << "Title : ";
	cin.getline(title,50);
	cin.getline(title, 50);
	cout << "Author (number) : "; 
	cin >> author_pos;
	cout << "Publication year : ";
	cin >> publication_year;
	cout << "Pages : ";
	cin >> pages;
	cout << "ISBN : ";
	cin >> ISBN;

	this->bb->Add(*(new Book(ab->Get(author_pos - 1), title, publication_year, pages, ISBN)));

	ofstream fout("Books.txt",ios::app);
	fout << endl << author_pos << "," << title << "," << publication_year << "," << pages << "," << ISBN;
	fout.close();
}

void Menu::RemoveAuthor() {
	system("cls");
	int author_pos;
	cout << "Author to remove (number) : "; cin >> author_pos;
	ab->Remove(--author_pos);

	ofstream fout("Authors.txt");
	int ind = ab->GetLastInd();
	for (int i = 0; i < ind+1; i++) {
		fout << ab->Get(i).GetFName() << "," << ab->Get(i).GetLName() << "," << ab->Get(i).GetMName() << "," << ab->Get(i).GetYOB() << "," << ab->Get(i).GetYOD();
		if (i != ind) fout << endl;
	}
	//fout.close();
	
}

//void Menu::RemoveBook() {
//	system("cls");
//	int book_pos;
//	cout << "Book to remove (number) : "; cin >> book_pos;
//	bb->Remove(--book_pos);
//
//	ifstream fin1("Book.txt");
//	ofstream fout1("temp.txt");
//	char t[100];
//	int ind = bb->GetLastInd();
//	for (int i = 0; i < ind+1; i++) {
//		if (i == book_pos) {
//			fin1.getline(t,50);
//			continue;
//		}
//		fin1.getline(t,50);
//		fout1 << t;
//	}
//	fout1.close();
//	fin1.close();
//
//	ifstream fin2("temp.txt");
//	ofstream fout2("Books.txt");
//	for (int i = 0; i < ind; i++) {
//		fin2.getline(t, 50, '\n');
//		fout2 << t;
//	}
//	fin2.close();
//	fout2.close();
//}

void Menu::ShowMenu() {
	//Presets
	bool exit = false;
	int rowN = 8, pPos = 1;
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
				cout << "Add author    ";
				break;
			case 2:
				cout << "Add book      ";
				break;
			case 3:
				cout << "Remove author ";
				break;
			case 4:
				cout << "Remove book(*)";
				break;
			case 5:
				cout << "Show authors  ";
				break;
			case 6:
				cout << "Show books    ";
				break;
			case 7:
				cout << "Settings      ";
				break;
			case 8:
				cout << "Exit          ";
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
				AddAuthor();
				break;
			case 2:
				AddBook();
				break;
			case 3:
				RemoveAuthor();
				break;
			case 4:
			//	RemoveBook();
				break;
			case 5:
				system("cls");
				ab->ShowAuthors();
				system("pause");
				break;
			case 6:
				system("cls");
				bb->ShowBooks();
				system("pause");
				break;
			case 7:
				ShowSettings();
				break;
			case 8:
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
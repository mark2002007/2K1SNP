#include <iostream>
#include "AuthorBase.h"
using namespace std;

AuthorBase::AuthorBase(int size) {
	this->size = size;
	this->lastInd = -1;
	this->author_list = new Author[size];
}

AuthorBase::~AuthorBase() {
	delete[]author_list;
}

void AuthorBase::ShowAuthors() {
	for (int i = 0; i <= lastInd; i++) {
		cout << i + 1 << endl;
		cout << "First Name : " << author_list[i].GetFName() << endl;
		cout << "Middle Name : " << author_list[i].GetMName() << endl;
		cout << "Last Name : " << author_list[i].GetLName() << endl;
		cout << "Year of Birth : " << author_list[i].GetYOB() << endl;
		cout << "Year of Death : " << author_list[i].GetYOD() << endl;
	}
}

void AuthorBase::Add(Author& author) {
	author_list[++lastInd] = author;
}

void AuthorBase::Remove(int ind) {
	for (int i = 0; i <= lastInd; i++) {
		if (i > ind) {
			author_list[i - 1] = author_list[i];
		}
	}
	author_list[lastInd--] = *(new Author());
}

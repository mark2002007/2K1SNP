#include <iostream>
#include "BookBase.h"
using namespace std;

BookBase::BookBase(int size) {
	this->size = size;
	this->lastInd = -1;
	this->book_list = new Book[size];
}
BookBase::~BookBase() {
	delete[] book_list;
}
void BookBase::Add(Book& book) {
	book_list[++lastInd] = book;
}
void BookBase::Remove(int ind) {
	for (int i = 0; i <= lastInd; i++) {
		if (i > ind) {
			book_list[i - 1] = book_list[i];
		}
	}
	book_list[lastInd--] = *(new Book());
}

void BookBase::ShowBooks() {
	for (int i = 0; i <= lastInd; i++) {
		cout << i + 1 << endl;
		cout << "Title : " << book_list[i].GetTitle() << endl;
		cout << "Author : " << book_list[i].GetAuthorFName() << " " << book_list[i].GetAuthorMName() << " " << book_list[i].GetAuthorLName() << endl;
		cout << "Publication year : " << book_list[i].GetPublicationYear() << endl;
		cout << "Pages : " << book_list[i].GetPages() << endl;
		cout << "ISBN : " << book_list[i].GetISBN() << endl;
	}
}
#include <iostream>
#include "Author.h"
using namespace std;
#ifndef BOOK_H
#define BOOK_H

class Book{
private:
	Author* author;
	string title;
	int publication_year;
	int pages;
	string ISBN;
public:
	Book(Author& = *(new Author), string = "None", int = 2020, int = 1, string = "999999999999X");
	~Book();
	void ShowInfo();

	string GetAuthorFName() { return author->GetFName(); }
	string GetAuthorLName() { return author->GetLName(); }
	string GetAuthorMName() { return author->GetMName(); }
	int GetAuthorYOB() { return author->GetYOB(); }
	int GetAuthorYOD() { return author->GetYOD(); }
	string GetTitle() { return title; }
	int GetPublicationYear() { return publication_year; }
	int GetPages() { return pages; }
	string GetISBN() { return ISBN; }
};

#endif // !BOOK_H
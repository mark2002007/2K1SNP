#include <iostream>
#include "Book.h"
using namespace std;

Book::Book(Author& author, string title, int publication_year, int pages, string ISBN) {
	this->title = title;
	this->author = &author;
	if (publication_year > 2020) throw "Publication year ERROR";
	this->publication_year = publication_year;
	if (pages < 1) throw "Pages number ERROR";
	this->pages = pages;
	if (ISBN.length() != 13) throw "ISBN ERROR";
	this->ISBN = ISBN;
}
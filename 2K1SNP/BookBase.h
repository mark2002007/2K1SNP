#include <iostream>
#include "Book.h"
using namespace std;

#ifndef BOOKBASE_H
#define BOOKBASE_H

class BookBase {
private:
	int size;
	int lastInd;
	Book* book_list;
public:
	//ctr
	BookBase(int = 0);
	//dtr
	~BookBase();
	//
	Book& Get(int ind) { return book_list[ind]; }
	int GetLastInd() { return lastInd; }
	void ShowBooks();

	void Add(Book& = *(new Book));
	void Remove(int);
};

#endif // !BOOKBASE_H

#include <iostream>
#include "Author.h"
using namespace std;

#ifndef AUTHORBASE_H
#define AUTHORBASE_H

class AuthorBase {
private:
	int size;
	int lastInd;
	Author* author_list;
public:
	AuthorBase(int = 0);
	~AuthorBase();
	int GetLastInd() { return lastInd; }
	void ShowAuthors();
	void Add(Author & = *(new Author));
	void Remove(int ind);
	Author& Get(int ind) { return author_list[ind]; }
};
#endif // !AUTHORBASE_H;
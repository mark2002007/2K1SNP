#pragma once

#include "Repository.h"
#include "Book.h"

class BookRepository {
private:
	Book** data;
	int maxSize;
	int current;
	bool sync;
	Repository<Author>* arep;
public:
	BookRepository(Repository<Author>& arep, bool sync = false);
	~BookRepository();

	void Add(Book& book);
	void Remove(int ind = 0);
	void Show();

	void ReadFromStorage();
	void WriteToStorage();
};
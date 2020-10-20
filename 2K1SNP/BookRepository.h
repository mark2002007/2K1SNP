#pragma once

#include "Repository.h"
#include "AuthorRepository.h"
#include "Book.h"

class BookRepository : public Repository {
private:
	AuthorRepository* arep;
public:
	BookRepository(AuthorRepository* arep, bool sync = false);
	~BookRepository();

	void Add(Book& book);
	void Remove(int num = 1);
	void Show();

	void ReadFromStorage();
	void WriteToStorage();
};
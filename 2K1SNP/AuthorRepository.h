#pragma once

#include "Repository.h"
#include "Author.h"

class AuthorRepository : public Repository {
public:
	AuthorRepository(bool sync = false);
	~AuthorRepository();

	void Add(Author& author);
	void Remove(int num = 1);
	Author* Get(int ind) { return (Author*)data[ind]; };
	void Show();

	void ReadFromStorage();
	void WriteToStorage();

	friend class BookRepository;
};
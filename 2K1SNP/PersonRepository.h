#pragma once

#include "Repository.h"
#include "Person.h"

class PersonRepository : Repository {
public:
	PersonRepository(bool sync = false);
	~PersonRepository();

	void Add(Person& person);
	void Remove(string type, int num = 1);
	void Show(string type);

	void ReadFromStorage();
	void WriteToStorage();
};
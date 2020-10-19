#include <iostream>
#include "Person.h"
using namespace std;

#ifndef PERSONBASE_H
#define PERSONBASE_H

class PersonBase {
private:
	int size;
	int lastInd = -1;
	Person** person_list;
public:
	PersonBase(int = 0);
	~PersonBase();
	int GetLastInd() { return lastInd; }

	void ShowAuthors();
	void ShowCustomers();
	void ShowEmployees();

	void Add(Person &person = *(new Person));
	void Remove(string type, int num = 1);

	Person* Get(string type, int num);
	Person* IndGet(int ind) { return person_list[ind]; }

	//Person& operator[] (const int index);
};
#endif // !PERSONBASE_H;
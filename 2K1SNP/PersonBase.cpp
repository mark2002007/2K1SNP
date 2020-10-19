#include <iostream>
#include "Author.h"
#include "Customer.h"
#include "Employee.h"
#include "PersonBase.h"
using namespace std;

PersonBase::PersonBase(int size) {
	this->size = size;
	this->person_list = new Person *[size];
}

PersonBase::~PersonBase() {
	for (int i = 0; i < size; i++) delete[]person_list[i];
	delete[] person_list;
}

void PersonBase::ShowAuthors() {
	int cnt = 0;
	for (int i = 0; i <= lastInd; i++) {
		if (static_cast<string>(typeid(person_list[i][0]).name()) == "class Author") {
			cout << ++cnt << endl;
			((Author*)person_list[i])->ShowInfo();
		}
	}
}

void PersonBase::ShowCustomers() {
	int cnt = 0;
	for (int i = 0; i <= lastInd; i++) {
		if (static_cast<string>(typeid(person_list[i][0]).name()) == "class Customer") {
			cout << ++cnt << endl;
			((Customer*)person_list[i])->ShowInfo();
		}
	}
}

void PersonBase::ShowEmployees() {
	int cnt = 0;
	for (int i = 0; i <= lastInd; i++) {
		if (static_cast<string>(typeid(person_list[i][0]).name()) == "class Employee") {
			cout << ++cnt << endl;
			((Employee*)person_list[i])->ShowInfo();
		}
	}
}

void PersonBase::Add(Person &person) {
	person_list[++lastInd] = &person;
}

void PersonBase::Remove(string type, int num) {
	int cnt = 0;
	for (int i = 0; i <= lastInd; i++) {
		if (static_cast<string>(typeid(person_list[i][0]).name()) == "class " + type) cnt++;
		if (cnt == num) {
			cnt++;
			continue;
		}
		if (cnt > num) person_list[i - 1] = person_list[i];
	}
	person_list[lastInd--] = new Person;
}

Person* PersonBase::Get(string type, int num) {
	int cnt = 0;
	for (int i = 0; i <= lastInd; i++) {
		if (static_cast<string>(typeid(person_list[i][0]).name()) == "class " + type) cnt++;
		if (cnt == num) return person_list[i];
	}
}
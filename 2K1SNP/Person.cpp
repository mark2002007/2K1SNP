#include <iostream>
#include "Person.h"
using namespace std;

Person::Person(string fName, string mName, string lName) {
	this->fName = fName;
	this->mName = mName;
	this->lName = lName;
}

void Person::ShowInfo() {
	cout << "First Name : " << fName << endl;
	cout << "Middle Name : " << mName << endl;
	cout << "Last Name : " << lName << endl;
}
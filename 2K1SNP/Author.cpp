#include <iostream>
#include "Author.h"
#include "Person.h"
using namespace std;

Author::Author(string fName, string mName, string lName, int yob, int yod) : Person(fName,mName,lName) {
	if (yob > 2002) throw "Year of Birth ERROR";
	this->yob = yob;
	if (yod > 2020) throw "Year of Death ERROR";
	this->yod = yod;
}

void Author::ShowInfo() {
	cout << "First Name : " << fName << endl;
	cout << "Middle Name : " << mName << endl;
	cout << "Last Name : " << lName << endl;
	cout << "Year of Birth : " << yob << endl;
	cout << "Year of Death : " << yod << endl;
}
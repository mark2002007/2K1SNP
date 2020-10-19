#include <iostream>
#include "Author.h"
using namespace std;

Author::Author(string fName, string lName, string mName, int yob, int yod) {
	this->fName = fName;
	this->lName = lName;
	this->mName = mName;
	if (yob > 2002) throw "Year of Birth ERROR";
	this->yob = yob;
	if(yod > 2020) throw "Year of Death ERROR";
	this->yod = yod;
}


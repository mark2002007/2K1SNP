#include <iostream>
using namespace std;

#ifndef AUTHOR_H
#define AUTHOR_H

class Author {
private:
	string fName;
	string lName;
	string mName;
	int yob;
	int yod;
public:
	Author(string = "", string = "", string = "", int = 0, int = 0);
	string GetFName() { return fName; }
	string GetLName() { return lName; }
	string GetMName() { return mName; }
	int GetYOB() { return yob; }
	int GetYOD() { return yod; }
};

#endif

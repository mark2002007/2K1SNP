#include <iostream>
#include "Person.h"
using namespace std;

#ifndef AUTHOR_H
#define AUTHOR_H

class Author : public Person {
private:
	int yob;
	int yod;
public:
	Author(string = "", string = "", string = "", int = 0, int = 0);
	void ShowInfo();
	int GetYOB() { return yob; }
	int GetYOD() { return yod; }
};

#endif

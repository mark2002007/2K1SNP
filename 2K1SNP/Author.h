#include <iostream>
#include <fstream>
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
	string GetStorageName() { return "Authors.txt"; }

	friend ifstream& operator>>(ifstream& fin, Author& a);
	friend ofstream& operator<<(ofstream& fout, Author& a);
	friend ostream& operator<<(ostream& out, Author& a);
};

#endif

#include <iostream>
#include <fstream>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person{
protected:
	string fName;
	string lName;
	string mName;
	//float A;
	//float B;
public:
	Person(string fName = "", string mName = "", string lName = "");
	void ShowInfo();
	string GetFName() { return fName; }
	string GetMName() { return mName; }
	string GetLName() { return lName; }

	//friend ifstream& operator>>(ifstream& fin, Person& p);
	//friend ofstream& operator<<(ofstream& fout, Person& p);
	//friend ostream& operator<<(ostream& out, Person& p);
};

#endif // !PERSON_H

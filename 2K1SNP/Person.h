#include <iostream>
#include "Entity.h"
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person : public Entity{
protected:
	string fName;
	string lName;
	string mName;
public:
	Person(string fName = "", string mName = "", string lName = "");
	virtual void ShowInfo();
	string GetFName() { return fName; }
	string GetMName() { return mName; }
	string GetLName() { return lName; }
};

#endif // !PERSON_H

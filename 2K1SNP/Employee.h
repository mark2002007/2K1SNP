#include <iostream>
#include "Person.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

class Employee : public Person {
private:
	int salary;
	int rank;
public:
	Employee(string = "", string = "", string = "", int = 0, int = 0);
	void ShowInfo();
	int GetSalary() { return salary; }
	int GetRank() { return rank; }
};

#endif // !EMPLOYEE_H
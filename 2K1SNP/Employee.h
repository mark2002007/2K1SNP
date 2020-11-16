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
	string GetStorageName() { return "Employees.txt"; }

	friend ifstream& operator>>(ifstream& fin, Employee& a);
	friend ofstream& operator<<(ofstream& fout, Employee& a);
	friend ostream& operator<<(ostream& out, Employee& a);
};

#endif // !EMPLOYEE_H
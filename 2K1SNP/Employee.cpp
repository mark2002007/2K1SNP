#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee(string fName, string mName, string lName, int salary, int rank) : Person(fName, mName, lName) {
	this->salary = salary;
	this->rank = rank;
}

void Employee::ShowInfo() {
	cout << "First Name : " << fName << endl;
	cout << "Middle Name : " << mName << endl;
	cout << "Last Name : " << lName << endl;
	cout << "Salary : " << salary << endl;
	cout << "Rank : " << rank << endl;
}
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

ifstream& operator>>(ifstream& fin, Employee& a)
{
	int max_len = 50;
	char fName[50], mName[50], lName[50], A[50], B[50], delim = ',';

	fin.get(fName, max_len, delim); fin.get();
	fin.get(mName, max_len, delim); fin.get();
	fin.get(lName, max_len, delim); fin.get();
	fin.get(A, max_len, delim); fin.get();
	fin.getline(B, max_len);

	a.fName = fName; a.mName = mName; a.lName = lName; a.salary = atoi(A); a.rank = atoi(B);

	return fin;
}

ofstream& operator<<(ofstream& fout, Employee& a)
{
	string delim = ",";
	fout << a.fName << delim
		<< a.mName << delim
		<< a.lName << delim
		<< a.salary << delim
		<< a.rank;
	return fout;
}

ostream& operator<<(ostream& out, Employee& a)
{
	string delim = ", ";
	out << a.fName << delim
		<< a.mName << delim
		<< a.lName << delim
		<< a.salary << delim
		<< a.rank;

	return out;
}
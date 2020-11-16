#include <iostream>
#include "Person.h"
using namespace std;

Person::Person(string fName, string mName, string lName) {
	this->fName = fName;
	this->mName = mName;
	this->lName = lName;
}

void Person::ShowInfo() {
	cout << "First Name : " << fName << endl;
	cout << "Middle Name : " << mName << endl;
	cout << "Last Name : " << lName << endl;
}

//ifstream& operator>>(ifstream& fin, Person& p)
//{
//	int max_len = 50;
//	char fName[50], mName[50], lName[50], A[50], B[50], delim = ',';
//
//	fin.get(fName, max_len, delim); fin.get();
//	fin.get(mName, max_len, delim); fin.get();
//	fin.get(lName, max_len, delim); fin.get();
//	fin.get(A, max_len, delim); fin.get();
//	fin.getline(B, max_len);
//
//	p.fName = fName; p.mName = mName; p.lName = lName; p.A = atoi(A); p.B = atoi(B);
//
//	return fin;
//}
//
//ofstream& operator<<(ofstream& fout, Person& p)
//{
//	string delim = ", ";
//	fout << endl << p.fName << delim
//		<< p.mName << delim
//		<< p.lName << delim
//		<< p.A << delim
//		<< p.B;
//	return fout;
//}
//
//ostream& operator<<(ostream& out, Person& p)
//{
//	string delim = ", ";
//	out << p.fName << delim
//		<< p.mName << delim
//		<< p.lName << delim
//		<< p.A << delim
//		<< p.B;
//
//	return out;
//}
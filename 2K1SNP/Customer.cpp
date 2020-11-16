#include <iostream>
#include "Customer.h"
using namespace std;

Customer::Customer(string fName, string mName, string lName, float balance, int purchases) : Person(fName,mName,lName) {
	this->balance = balance;
	this->purchases = purchases;
}

void Customer::ShowInfo() {
	cout << "First Name : " << fName << endl;
	cout << "Middle Name : " << mName << endl;
	cout << "Last Name : " << lName << endl;
	cout << "Balance : " << balance << endl;
	cout << "Amount of purchases : " << purchases << endl;
}

ifstream& operator>>(ifstream& fin, Customer& a)
{
	int max_len = 50;
	char fName[50], mName[50], lName[50], A[50], B[50], delim = ',';

	fin.get(fName, max_len, delim); fin.get();
	fin.get(mName, max_len, delim); fin.get();
	fin.get(lName, max_len, delim); fin.get();
	fin.get(A, max_len, delim); fin.get();
	fin.getline(B, max_len);

	a.fName = fName; a.mName = mName; a.lName = lName; a.balance = atoi(A); a.purchases = atoi(B);

	return fin;
}

ofstream& operator<<(ofstream& fout, Customer& a)
{
	string delim = ",";
	fout << a.fName << delim
		<< a.mName << delim
		<< a.lName << delim
		<< a.balance << delim
		<< a.purchases;
	return fout;
}

ostream& operator<<(ostream& out, Customer& a)
{
	string delim = ", ";
	out << a.fName << delim
		<< a.mName << delim
		<< a.lName << delim
		<< a.balance << delim
		<< a.purchases;

	return out;
}
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
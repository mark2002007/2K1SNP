#include <iostream>
#include "CustomerBase.h"
using namespace std;

CustomerBase::CustomerBase(int size) {
	this->size = size;
	this->lastInd = -1;
	this->customer_list = new Customer[size];
}

CustomerBase::~CustomerBase() {
	delete[]customer_list;
}

void CustomerBase::ShowCustomers() {
	for (int i = 0; i <= lastInd; i++) {
		cout << i + 1 << endl;
		cout << "First Name : " << customer_list[i].GetFName() << endl;
		cout << "Middle Name : " << customer_list[i].GetMName() << endl;
		cout << "Last Name : " << customer_list[i].GetLName() << endl;
		cout << "Balance : " << customer_list[i].GetBalance() << endl;
		cout << "Amount of Purchases : " << customer_list[i].GetPurchases() << endl;
	}
}

void CustomerBase::Add(Customer& customer) {
	customer_list[++lastInd] = customer;
}

void CustomerBase::Remove(int ind) {
	for (int i = 0; i <= lastInd; i++) {
		if (i > ind) {
			customer_list[i - 1] = customer_list[i];
		}
	}
	customer_list[lastInd--] = *(new Customer());
}

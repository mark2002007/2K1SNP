#include <iostream>
#include "Person.h"
using namespace std;
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer : public Person {
private:
	float balance;
	int purchases;
public:
	Customer(string = "", string = "", string = "", float = 0, int = 0);
	void ShowInfo();
	float GetBalance() { return balance; }
	int GetPurchases() { return purchases; }
	string GetStorageName() { return "Customers.txt"; }

	friend ifstream& operator>>(ifstream& fin, Customer& c);
	friend ofstream& operator<<(ofstream& fout, Customer& c);
	friend ostream& operator<<(ostream& out, Customer& c);
};

#endif // !CUSTOMER_H

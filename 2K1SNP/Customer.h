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
};

#endif // !CUSTOMER_H

#include <iostream>
#include "Customer.h"
using namespace std;

#ifndef CUSTOMERBASE_H
#define CUSTOMERBASE_H

class CustomerBase {
private:
	int size;
	int lastInd;
	Customer* customer_list;
public:
	CustomerBase(int = 0);
	~CustomerBase();
	int GetLastInd() { return lastInd; }
	void ShowCustomers();
	void Add(Customer& = *(new Customer));
	void Remove(int ind);
	Customer& Get(int ind) { return customer_list[ind]; }
};
#endif // !AUTHORBASE_H;
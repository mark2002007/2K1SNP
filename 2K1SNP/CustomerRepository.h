#pragma once

#include "Repository.h"
#include "Customer.h"

class CustomerRepository : public Repository {
public:
	CustomerRepository(bool sync = false);
	~CustomerRepository();

	void Add(Customer& customer);
	void Remove(int num = 1);
	void Show();

	void ReadFromStorage();
	void WriteToStorage();
};
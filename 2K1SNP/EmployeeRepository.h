#pragma once

#include "Repository.h"
#include "Employee.h"

class EmployeeRepository : public Repository {
public:
	EmployeeRepository(bool sync = false);
	~EmployeeRepository();

	void Add(Employee& employee);
	void Remove(int num = 1);
	void Show();

	void ReadFromStorage();
	void WriteToStorage();
};
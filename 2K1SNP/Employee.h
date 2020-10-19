#include <iostream>
#include "Person.h"
using namespace std;

class Employee : public Person {
private:
	int salary;
	int rank;
public:
	Employee(string = "", string = "", string = "", int = 0, int = 0);
	void ShowInfo();
	int GetSalary() { return salary; }
	int GetRank() { return rank; }
};
#include <iostream>
#include <fstream>
#include "PersonRepository.h"
#include "Author.h"
#include "Customer.h"
#include "Employee.h"
using namespace std;

PersonRepository::PersonRepository(bool sync) : Repository(sync) {
	ReadFromStorage();
}

PersonRepository::~PersonRepository() {
	WriteToStorage();
}

void PersonRepository::Add(Person& person) {
	Repository::Add(&person);
}

void PersonRepository::Remove(string type, int num) {
	int cnt = 0;
	for (int i = 0; i <= current; i++) {
		if (static_cast<string>(typeid(data[i][0]).name()) == "class " + type) cnt++;
		if (cnt == num) {
			cnt++;
			continue;
		}
		if (cnt > num) data[i - 1] = data[i];
	}
	data[current--] = new Person();
}

void PersonRepository::Show(string type) {
	int cnt = 0;
	for (int i = 0; i <= current; i++) {
		cout << static_cast<string>(typeid(data[i][0]).name()) << " == " << "class" + type;
		if (static_cast<string>(typeid(data[i][0]).name()) == "class" + type) {
			cout << ++cnt << endl;
			if(type == "Author") ((Author*)data[i])->ShowInfo();
			else if(type == "Customer") ((Customer*)data[i])->ShowInfo();
			else if(type == "Employee") ((Employee*)data[i])->ShowInfo();
		}
	}
}

void PersonRepository::ReadFromStorage() {
	ifstream a_in("Authors.txt");
	ifstream c_in("Customers.txt");
	ifstream e_in("Employees.txt");

	char fName[50], mName[50], lName[50], A[50], B[50];
	while (a_in >> fName >> mName >> lName >> A >> B) 
		Add(*(new Author(fName, mName, lName, atoi(A), atoi(B))));
	while (c_in >> fName >> mName >> lName >> A >> B) Add(*(new Customer(fName, mName, lName, atoi(A), atof(B))));
	while (e_in >> fName >> mName >> lName >> A >> B) Add(*(new Employee(fName, mName, lName, atoi(A), atoi(B))));

	cout << "Authors : " << endl;
	Show("Author");
	
	e_in.close();
	c_in.close();
	a_in.close();
}

void PersonRepository::WriteToStorage() {
	ofstream a_out("Authors.txt");
	ofstream c_out("Customers.txt");
	ofstream e_out("Employees.txt");
	int ind = current;
	for (int i = 0; i <= ind; i++) {
		if (static_cast<string>(typeid(data[i]).name()) == "class Author") {
			Author* a = (Author*)data[i];
			a_out << endl << a->GetFName()
				<< " " << a->GetMName()
				<< " " << a->GetLName()
				<< " " << a->GetYOB()
				<< " " << a->GetYOD();
		}
		else if (static_cast<string>(typeid((data[i])[0]).name()) == "class Customer") {
			Customer* c = (Customer*)data[i];
			c_out << endl << c->GetFName()
				<< " " << c->GetMName()
				<< " " << c->GetLName()
				<< " " << c->GetBalance()
				<< " " << c->GetPurchases();
		}
		else if (static_cast<string>(typeid((data[i])[0]).name()) == "class Employee") {
			Employee* e = (Employee*)data[i];
			e_out << endl << e->GetFName()
				<< " " << e->GetMName()
				<< " " << e->GetLName()
				<< " " << e->GetSalary()
				<< " " << e->GetRank();
		}
	}
	e_out.close();
	c_out.close();
	a_out.close();
}

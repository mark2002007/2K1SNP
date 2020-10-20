#include "EmployeeRepository.h"
#include <fstream>
using namespace std;

EmployeeRepository::EmployeeRepository(bool sync) : Repository(sync)
{
	ReadFromStorage();
}

EmployeeRepository::~EmployeeRepository()
{
}

void EmployeeRepository::Add(Employee& employee)
{
	Repository::Add(&employee);
}

void EmployeeRepository::Remove(int num)
{
	for (int i = 0; i <= current; i++) {
		if (i == num - 1) continue;
		else if (i > num - 1) data[i - 1] = data[i];
	}
	data[current--] = new Employee();
	if (sync)
		WriteToStorage();
}

void EmployeeRepository::Show()
{
	for (int i = 0; i <= current; i++) {
		cout << i + 1 << endl;
		((Employee*)data[i])->ShowInfo();
	}
}

void EmployeeRepository::ReadFromStorage()
{
	ifstream e_in("Employees.txt");
	char fName[50], mName[50], lName[50], A[50], B[50];
	bool t_sync = false;
	if (sync) { //Обхід запису в файл при його зчитуванні, інакшими словами - "костиль"
		t_sync = sync;
		sync = !sync;
	}
	while (e_in >> fName >> mName >> lName >> A >> B)
		Add(*(new Employee(fName, mName, lName, atoi(A), atoi(B))));
	if (t_sync) sync = t_sync; //Кінець обходу
	e_in.close();
}

void EmployeeRepository::WriteToStorage()
{
	ofstream e_out("Employees.txt");
	int ind = current;
	for (int i = 0; i <= ind; i++) {
		Employee* a = (Employee*)data[i];
		e_out << endl << a->GetFName()
			<< " " << a->GetMName()
			<< " " << a->GetLName()
			<< " " << a->GetSalary()
			<< " " << a->GetRank();
	}
	e_out.close();
}
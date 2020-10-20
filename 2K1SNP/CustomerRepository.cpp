#include "CustomerRepository.h"
#include <fstream>
using namespace std;

CustomerRepository::CustomerRepository(bool sync) : Repository(sync)
{
	ReadFromStorage();
}

CustomerRepository::~CustomerRepository()
{
}

void CustomerRepository::Add(Customer& customer)
{
	Repository::Add(&customer);
}

void CustomerRepository::Remove(int num)
{
	for (int i = 0; i <= current; i++) {
		if (i == num - 1) continue;
		else if (i > num - 1) data[i - 1] = data[i];
	}
	data[current--] = new Customer();
	if (sync)
		WriteToStorage();
}

void CustomerRepository::Show()
{
	for (int i = 0; i <= current; i++) {
		cout << i + 1 << endl;
		((Customer*)data[i])->ShowInfo();
	}
}

void CustomerRepository::ReadFromStorage()
{
	ifstream c_in("Customers.txt");
	char fName[50], mName[50], lName[50], A[50], B[50];
	bool t_sync = false;
	if (sync) { //Обхід запису в файл при його зчитуванні, інакшими словами - "костиль"
		t_sync = sync;
		sync = !sync;
	}
	while (c_in >> fName >> mName >> lName >> A >> B)
		Add(*(new Customer(fName, mName, lName, atoi(A), atoi(B))));
	if (t_sync) sync = t_sync; //Кінець обходу
	c_in.close();
}

void CustomerRepository::WriteToStorage()
{
	ofstream c_out("Customers.txt");
	int ind = current;
	for (int i = 0; i <= ind; i++) {
		Customer* a = (Customer*)data[i];
		c_out << endl << a->GetFName()
			<< " " << a->GetMName()
			<< " " << a->GetLName()
			<< " " << a->GetBalance()
			<< " " << a->GetPurchases();
	}
	c_out.close();
}
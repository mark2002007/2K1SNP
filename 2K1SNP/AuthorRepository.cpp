#include "AuthorRepository.h"
#include <fstream>
using namespace std;

AuthorRepository::AuthorRepository(bool sync) : Repository(sync)
{
	ReadFromStorage();
}

AuthorRepository::~AuthorRepository()
{
}

void AuthorRepository::Add(Author& author)
{
	Repository::Add(&author);
}

void AuthorRepository::Remove(int num)
{
	for (int i = 0; i <= current; i++) {
		if (i == num - 1) continue;
		else if (i > num - 1) data[i - 1] = data[i];
	}
	data[current--] = new Author();
	if (sync)
		WriteToStorage();
}

void AuthorRepository::Show()
{
	for (int i = 0; i <= current; i++) {
			cout << i + 1 << endl;
			((Author*)data[i])->ShowInfo();
	}
}

void AuthorRepository::ReadFromStorage()
{
	ifstream a_in("Authors.txt");
	char fName[50], mName[50], lName[50], A[50], B[50];
	bool t_sync = false;
	if (sync) { //Обхід запису в файл при його зчитуванні, інакшими словами - "костиль"
		t_sync = sync;
		sync = !sync;
	}
	while (a_in >> fName >> mName >> lName >> A >> B)
		Add(*(new Author(fName, mName, lName, atoi(A), atoi(B))));
	if (t_sync) sync = t_sync; //Кінець обходу
	a_in.close();
}

void AuthorRepository::WriteToStorage()
{
	ofstream a_out("Authors.txt");
	int ind = current;
	for (int i = 0; i <= ind; i++) {
		Author* a = (Author*)data[i];
		a_out << endl << a->GetFName()
			<< " " << a->GetMName()
			<< " " << a->GetLName()
			<< " " << a->GetYOB()
			<< " " << a->GetYOD();
	}
	a_out.close();
}
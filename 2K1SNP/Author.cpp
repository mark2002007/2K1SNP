#include "Author.h"
using namespace std;

Author::Author(string fName, string mName, string lName, int yob, int yod) : Person(fName,mName,lName) {
	if (yob > 2002) throw "Year of Birth ERROR";
	this->yob = yob;
	if (yod > 2020) throw "Year of Death ERROR";
	this-> yod = yod;
}

void Author::ShowInfo() {
	cout << "First Name : " << fName << endl;
	cout << "Middle Name : " << mName << endl;
	cout << "Last Name : " << lName << endl;
	cout << "Year of Birth : " << yob << endl;
	cout << "Year of Death : " << yod << endl;
}

ifstream& operator>>(ifstream& fin, Author& a)
{
	int max_len = 50;
	char fName[50], mName[50], lName[50], A[50], B[50], delim = ',';

	fin.get(fName, max_len, delim); fin.get();
	fin.get(mName, max_len, delim); fin.get();
	fin.get(lName, max_len, delim); fin.get();
	fin.get(A, max_len, delim); fin.get();
	fin.getline(B, max_len);

	a.fName = fName; a.mName = mName; a.lName = lName; a.yob = atoi(A); a.yod = atoi(B);

	return fin;
}

ofstream& operator<<(ofstream& fout, Author& a)
{
	string delim = ",";
	fout << a.fName << delim
		<< a.mName << delim
		<< a.lName << delim
		<< a.yob << delim
		<< a.yod;
	return fout;
}

ostream& operator<<(ostream& out, Author& a)
{
	string delim = ", ";
	out << a.fName << delim
		<< a.mName << delim
		<< a.lName << delim
		<< a.yob << delim
		<< a.yod;

	return out;
}
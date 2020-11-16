#include <iostream>
#include "Book.h"
using namespace std;

Book::Book(Author& author, string title, int publication_year, int pages, string ISBN) {
	this->title = title;
	this->author = &author;
	if (publication_year > 2020) throw "Publication year ERROR";
	this->publication_year = publication_year;
	if (pages < 1) throw "Pages number ERROR";
	this->pages = pages;
	if (ISBN.length() != 13) throw "ISBN ERROR";
	this->ISBN = ISBN;
}

Book::~Book() {
	delete[] author;
}

void Book::ShowInfo()
{
	cout << "Author : " << author->GetFName() << " " << author->GetMName() << " " << author->GetLName() << endl;
	cout << "Title : " << title << endl;
	cout << "Publication Year : " << publication_year << endl;
	cout << "Number of Pages : " << pages << endl;
	cout << "ISBN : " << ISBN << endl;
}

//ifstream& operator>>(ifstream& fin, Author& a)
//{
//	int max_len = 50;
//	char fName[50], mName[50], lName[50], A[50], B[50], delim = ',';
//
//	fin.get(fName, max_len, delim); fin.get();
//	fin.get(mName, max_len, delim); fin.get();
//	fin.get(lName, max_len, delim); fin.get();
//	fin.get(A, max_len, delim); fin.get();
//	fin.getline(B, max_len);
//
//	a.fName = fName; a.mName = mName; a.lName = lName; a.yob = atoi(A); a.yod = atoi(B);
//
//	return fin;
//}

//ofstream& operator<<(ofstream& fout, Author& a)
//{
//	string delim = ",";
//	fout << a.fName << delim
//		<< a.mName << delim
//		<< a.lName << delim
//		<< a.yob << delim
//		<< a.yod;
//	return fout;
//}
//
//ostream& operator<<(ostream& out, Author& a)
//{
//	string delim = ", ";
//	out << a.fName << delim
//		<< a.mName << delim
//		<< a.lName << delim
//		<< a.yob << delim
//		<< a.yod;
//
//	return out;
//}
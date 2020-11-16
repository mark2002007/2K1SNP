#include "Repository.h"
#include "BookRepository.h"
#include <fstream>
using namespace std;


BookRepository::BookRepository(Repository<Author>& arep, bool sync)
{
	this->sync = sync;
	maxSize = 10;
	data = new Book * [maxSize];
	current = -1;
	this->arep = &arep;
	ReadFromStorage();
}

BookRepository::~BookRepository()
{
}

void BookRepository::Add(Book& book)
{
	data[++current] = &book;
	if (sync)
		WriteToStorage();
}

void BookRepository::Remove(int ind)
{
	for (int i = ind + 1; i <= current; i++) data[i - 1] = data[i];
	current--;
	if (sync)
		WriteToStorage();
}

void BookRepository::Show()
{
	for (int i = 0; i <= current; i++) {
		cout << i + 1 << endl;
		((Book*)data[i])->ShowInfo();
	}
}

void BookRepository::ReadFromStorage()
{
	ifstream b_in("Books.txt");
	char author_pos[10], title[50], publication_year[10], pages[10], ISBN[15];
	bool t_sync = false;

	if (sync) { //Обхід запису в файл при його зчитуванні, інакшими словами - "костиль"
		t_sync = sync;
		sync = !sync;
	}

	while (!b_in.eof()) {
		b_in.get(author_pos, 50, ','); b_in.get();
		b_in.get(title, 50, ','); b_in.get();
		b_in.get(publication_year, 50, ','); b_in.get();
		b_in.get(pages, 50, ','); b_in.get();
		b_in.getline(ISBN, 50);
		Add(*(new Book((*arep)[atoi(author_pos)-1], title, atoi(publication_year), atoi(pages), ISBN)));
	}

	if (t_sync) sync = t_sync; //Кінець обходу
	
	b_in.close();
}

void BookRepository::WriteToStorage()
{
	ofstream b_out("Books.txt");
	for (int i = 0; i <= current; i++) {

		Book* b = (Book*)data[i];  /*(Book*)data[i];*/
		int arep_l_ind = arep->GetCurrent(), a_pos = -1;
		for (int i = 0; i <= arep_l_ind; i++) { //Find author
			Author* a = &(*arep)[i];
			if (a->GetFName() == b->GetAuthorFName() &&
				a->GetMName() == b->GetAuthorMName() &&
				a->GetLName() == b->GetAuthorLName()) {
				a_pos = i;
				break;
			}
		}
		if (a_pos != -1) {
			b_out << a_pos+1
				<< "," << b->GetTitle()
				<< "," << b->GetPublicationYear()
				<< "," << b->GetPages()
				<< "," << b->GetISBN();
			if (i < current) b_out << endl;
		}
		
	}
	b_out.close();
}
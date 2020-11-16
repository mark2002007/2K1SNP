#pragma once

#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Repository
{
protected:
	T* data;
	int maxSize;
	int current;
	bool sync;

	void ReadFromStorage();
	void WriteToStorage();
	string GetStorageName() { T t; return t.GetStorageName(); }
public:
	Repository(bool sync = false);
	~Repository();
	
	int GetCurrent() { return current; }

	void Show();
	T& operator[](const int ind) { return data[ind]; }
	void Add(T& elem);
	void Remove(int ind);
	
};

template<class T>
void Repository<T>::ReadFromStorage() {
	ifstream fin(GetStorageName());
	char delim = ',';
	bool t_sync = false;
	if (sync) { //Обхід запису в файл при його зчитуванні, інакшими словами - "костиль"
		t_sync = sync;
		sync = !sync;
	}
	while (!fin.eof()) {
		T t;
		fin >> t;
		Add(t);
	}
	if (t_sync) sync = t_sync; //Кінець обходу
	fin.close();
}

template<class T>
void Repository<T>::WriteToStorage() {
	ofstream fout(GetStorageName());
	for (int i = 0; i <= current; i++)
	{
		fout << data[i];
		if (i < current)
			fout << endl;
	}

	fout.close();
}

template <class T>
Repository<T>::Repository(bool sync)
{
	this->sync = sync;
	maxSize = 10;
	data = new T [maxSize];
	current = -1;
	ReadFromStorage();
}

template <class T>
Repository<T>::~Repository()
{
	WriteToStorage();
	delete[] data;
}

template<class T>
void Repository<T>::Show()
{
	for (int i = 0; i <= current; i++) {
		cout << i + 1 << endl;
		data[i].ShowInfo();
	}
}

template<class T>
void Repository<T>::Add(T& elem)
{
	data[++current] = elem;
	if (sync)
		WriteToStorage();
}

template<class T>
void Repository<T>::Remove(int ind)
{
	for (int i = ind + 1; i <= current; i++) data[i - 1] = data[i];
	current--;
	if (sync)
		WriteToStorage();
}
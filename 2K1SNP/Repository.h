#pragma once

#include "Entity.h"

class Repository
{
protected:
	Entity** data;
	int maxSize;
	int current;
	bool sync;

	void Add(Entity*);
	virtual void ReadFromStorage() {}
	virtual void WriteToStorage() {}

public:
	Repository(bool sync = false);
	~Repository();
};
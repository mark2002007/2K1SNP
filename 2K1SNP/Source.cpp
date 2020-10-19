#include <iostream>
#include "Book.h"
#include "Author.h"
#include "BookBase.h"
#include "AuthorBase.h" 
#include "Menu.h"
using namespace std;

int main() {
	Menu m1("Menu", "ORDERED", "<");
	m1.ShowMenu();
	return 0;
}
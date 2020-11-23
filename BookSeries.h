#pragma once
#include <string>
#include <vector>
#include "Book.h"
#include"Node.h"
using namespace std;
/*! Book class.*/
class BookSeries {
private:
	vector<Book*> books;
	int id;
public:
	BookSeries(vector<Book*>books, int id);
	Book* GetBook(int i);
	int GetVectorSize();
	int GetId();
	bool way;
};

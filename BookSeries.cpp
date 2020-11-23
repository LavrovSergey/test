#include "BookSeries.h"
BookSeries::BookSeries(vector<Book*>books, int id) {
	this->books = books;
	this->id = id++;
	this->way = way;
};
Book* BookSeries::GetBook(int i) { return books[i]; };
int BookSeries::GetVectorSize() { return books.size(); };
int BookSeries::GetId() { return id; };
bool way;
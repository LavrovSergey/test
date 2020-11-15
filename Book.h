#pragma once
#include <string>
#include <vector>

/*! Book class.*/
class Book {
public:
	string data; //name of the book
	vector<std::string> authors;
	int v;
	int d, m, y;
	int pages;
	string plot;
	int id = 0;
	bool way;
};
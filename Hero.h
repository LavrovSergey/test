#pragma once
#include <string>
#include <vector>

/*! Character class.*/
class Hero {
public:
	string data; //name of the hero
	int v;
	vector<string> names;
	int m;
	multimap<int, string> hb;
	int id = 0;
	bool way;
};
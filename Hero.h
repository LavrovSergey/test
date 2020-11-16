#pragma once
#include <string>
#include <vector>

/*! Character class.*/
class Hero {
private:
	string data; //name of the hero
	int v;
	vector<string> names;
	int id = 0;
public:
	Hero(string data,int v, vector<string> names, int id) {

		this->data = data;
		this->names = names;
		this->v = v;
		this->id = id;
		this->way = way;
	};
	string GetData() { return data; };
	string GetName(int i) { return names[i]; };
	/*int GetVectorSize() { return v.size(); };*/
	/*std::vector<T> GetVectorF() { return v; };*/
	int GetId() { return id; };
	bool way;
};
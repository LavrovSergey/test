#pragma once
#include <vector>
/*! @param T -data type*/
template<class T>
/*! Template node class.*/
class Part1 {
private:
	T data;
	std::vector<T> v;
	int id = 0;
public:
	Part1(T data, std::vector<T> v, int id, bool way){
		this->data = data;
		this->v = v;
		this->id = id;
		this->way = way;
	};
	T GetData() { return data; };
	T GetVector(int i) { return v[i]; };
	int GetVectorSize() { return v.size(); };
	std::vector<T> GetVectorF() { return v; };
	int GetId() { return id; };
	bool GetWay() { return way; };
	bool way;
};
#pragma once
#include "List.cpp"
#include <string>
class Hash
{
	List<string>* arr;
	int size;
	/*int count;
	int val;
	int key;*/

public:
	Hash();
	Hash(int);
	void add(int, string);
	void print();
	int search(string);
	//void std();


};


#pragma once
#include <iostream>
#include <fstream>
#include "TreeNode.cpp"
#include "stackArray.cpp"
#include "queue.cpp"
//#include "List.cpp"
#include <cstring>
#include <string>
//#include "hash.h"
using namespace std;
template <class T>
class Image
{
private:
	
	T **arr;
	T pixel;
	int row;
	int col;
	int on;
	int off;
	string name;
	List<int> rlc;
	Hash h;
public:
	fstream logout;

	Image();
	Image(string filename);
	~Image();
	//T array(int, int);
	void read(string);
	void Print();
	void save();
	int mean();
	void on_off();
	float average_black();
	T getPixel(int, int);
	void setPixel(int, int, T);
	void ConvertToNegative();
	int getSize();
	void queue_cce(int, int);
	void stack_cce(int, int);
	void RLC();
	void saveRLC();
	void readRLC();
	int blackRLC();
	void ConvertToNegativeRLC();
	void hashTable();
	void displayHashTable();

	void quadTree();
};


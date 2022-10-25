#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

class LFU
{
private:
	size_t size;
	size_t count;
	size_t min;
	map <string, int> My_map;

public:
	LFU(size_t size1);
	~LFU();

	map<string, int>::iterator find_value(const int value);
	int find_minimum();
	int get_min();

	bool find_and_add(const string &address);

	void print();
	void print_address(const string &address);
};













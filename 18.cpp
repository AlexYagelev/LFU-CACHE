#include "18.h"

using namespace std;

LFU::LFU(size_t size)
{
	 this->size = size;
	 count = 0;
}

LFU::~LFU()
{
	My_map.clear();
}


map <string, int>::iterator LFU::find_value(const int value)
{
	map<string, int>::iterator it;
	it = My_map.begin();

    while (it!=My_map.end())
    {
        if ((*it).second==value)
		return it;
        ++it;
    }
    return My_map.end();
}

int LFU::find_minimum()
{
	map<string, int>::iterator it;
	it = My_map.begin();
	int min = (*it).second;
	while (it!=My_map.end())
	{
		if (min > (*it).second)
			min = (*it).second;
		++it;
	}
    return min;
}

int LFU::get_min()
{
	return min;
}


bool LFU::find_and_add(const string &address)
{
	auto result = My_map.find(address);
	if (result == My_map.end())
	{
		if (count < size)
		{
			My_map.insert (pair<string,int>(address, 1));
			min = 1;
			count++;
		}
		else
		{
			auto res = find_value(min);
			My_map.erase(res);

			My_map.insert (pair<string,int>(address, 1));
		}
		return false;
	}
	else
	{
		My_map[address] += 1;
		int value = My_map[address];
		min = find_minimum();
	}
	return true;
}

void LFU::print()
{
	for (auto it = My_map.begin(); it != My_map.end(); ++it)
		cout <<  it->first << " : " << it->second << endl;
}

void LFU::print_address(const string &address)
{
	auto it = My_map.find(address);
		cout <<  it->first << " : " << it->second << endl;
}

bool LFU::find(const string &address)
{
	auto result = My_map.find(address);

	if (result != My_map.end())
	{
		My_map[address] += 1;
		int value = My_map[address];
		min = find_minimum();
		return true;
	}
	else
		return false;
}

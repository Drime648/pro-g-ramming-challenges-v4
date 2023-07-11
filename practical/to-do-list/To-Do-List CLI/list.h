#ifndef TO_DO_LIST
#define TO_DO_LIST

#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using std::cout;
class List
{
public:

	vector<string> items;
	void add(string name);
	void print();
	void deleteItem(int idx);
	void printOptions();

};
#endif


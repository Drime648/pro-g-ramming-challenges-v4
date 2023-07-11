#include "list.h"
#include <exception>
void List::add(string name)
{
	items.push_back(name);
}

void List::print()
{
	
	int i = 0;

	for (string s : items) {
		printf("%d\t%s\n", i, s.c_str());
		i++;
	}
	printOptions();
}

void List::deleteItem(int idx)
{
	if (idx >= items.size()) {
		throw(20);
	}
	else {
		items.erase(items.begin() + idx);
	}
	
	
}

void List::printOptions()
{
	cout << "\nto delete item, type del [index]\n";
	cout << "to add a task, type add [task name]\n";

}

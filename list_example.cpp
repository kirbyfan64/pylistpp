#include <list.hpp>
#include <iostream>

// An example.

int main()
{
	list<int> mylist;
	mylist.append(5);
	mylist.append(7);
	int count = mylist.count(5);
	std::cout << count << std::endl;
	std::cout << mylist.pop(0) << std::endl;
	std::cout << mylist.index(7);
	return 0;
}
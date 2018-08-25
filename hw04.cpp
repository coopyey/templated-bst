//File: main.cpp

#include <fstream>
#include "BST.hpp"
#include "DayOfYear.hpp"

int main() {
	Tree::BST<int> ints(666);
	Tree::BST<DayOfYear> days;

	std::cout << "Day of year tree created empty, integer tree created with value 666.\n\n";

	//Modifications could be made to take in a file if desired.
	//Not made to do this due to assignment requirements.
	ints.insert(246);
	ints.insert(1);
	ints.insert(153);
	ints.insert(356);
	ints.insert(4);
	ints.insert(687);
	ints.insert(2);
	ints.insert(789);
	ints.insert(985);
	ints.insert(3);
	ints.insert(654); //11 total values inserted for a tree of 12

	std::cout << "Integer file done processing. Traversing:\n";
	
	ints.traverse();

	std::cout << "\nInteger tree done. Moving on to day of year tree.\n\n";
	std::cout << "Day of year tree populated with included dates.txt file. Please refer to it for test cases.";
	std::cout << " There are twelve valid entries out of sixteen total test cases.\n";

	std::ifstream ifs;
	ifs.open("dates.txt");

	if (!ifs.is_open()) {
		std::cout << "Failed to open data file.\n";
		exit(1);
	}

	for (unsigned int j = 0; j <= 16; j++) {
		DayOfYear temp;
		ifs >> temp;
		days.insert(temp);
	}

	std::cout << "\nDay of year file done processing. Traversing:\n";
	days.traverse();
	std::cout << "\nDay of year tree done. Exiting.";

	return 0;
}
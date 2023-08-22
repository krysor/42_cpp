#include "iter.hpp"
#include <iostream>
#include <iomanip>

#define WIDTH 10

int main( void ) {
	int			arri[] = {1, 2, 3, 4, 5};
	char		arrc[] = {'a', 'b', 'c', 'd'};


	std::cout << "___BEFORE___" << std::endl;

	std::cout << std::left << std::setw(WIDTH) << "arri" << ": ";
	for (unsigned int i = 0; i < sizeof(arri)/sizeof(int); i++) {
		std::cout << std::to_string(arri[i]) << " ";
	}
	std::cout << std::endl;

	std::cout << std::left << std::setw(WIDTH) << "arrc" << ": ";
	for (unsigned int i = 0; i < sizeof(arrc)/sizeof(char); i++) {
		std::cout << arrc[i] << " ";
	}
	std::cout << std::endl;


	::iter(arri, sizeof(arri)/sizeof(int), ::dummy<int>);
	::iter(arrc, sizeof(arrc)/sizeof(char), ::dummy<char>);


	std::cout << "___AFTER___" << std::endl;

	std::cout << std::left << std::setw(WIDTH) << "arri" << ": ";
	for (unsigned int i = 0; i < sizeof(arri)/sizeof(int); i++) {
		std::cout << std::to_string(arri[i]) << " ";
	}
	std::cout << std::endl;

	std::cout << std::left << std::setw(WIDTH) << "arrc" << ": ";
	for (unsigned int i = 0; i < sizeof(arrc)/sizeof(char); i++) {
		std::cout << arrc[i] << " ";
	}
	std::cout << std::endl;


	return 0;
}

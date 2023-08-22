#include "easyfind.hpp"
#include <vector>
#include <iostream>

#define SIZE 10

int main( void ) {
	std::vector<int> v(SIZE);

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		v[i] = i;
	}
	
	std::cout << easyfind(v, 0) - v.begin() << std::endl;

	return (EXIT_SUCCESS);
}

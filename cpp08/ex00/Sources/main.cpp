#include "easyfind.hpp"
//#include <array>
#include <vector>
#include <deque>
//#include <forward_list>
#include <list>
#include <iostream>

#define SIZE 1000

template <typename T>
void	printNonList(std::string containerName, T& container, int target)
{
	try {
		int	i = easyfind(container, target) - container.begin(); 
		std::cout << "Number found inside " << containerName << " at index: " << std::to_string(i) << std::endl; 	
	}
	catch (std::exception & e) {
		std::cout << e.what() << " " << containerName <<  std::endl;
	}
}

template <typename T>
void	printList(std::string containerName, T& container, int target)
{	
	try {
		(void)easyfind(container, target);
		std::cout << "the number " << std::to_string(target) << " was found inside the " << containerName << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << " " << containerName <<  std::endl;
	}
}

int main( void ) {

	//std::array<int, SIZE>	a;
	std::vector<int>		v(SIZE);
	std::deque<int>			d(SIZE);
	//std::forward_list<int>	fl;
	std::list<int>			l;	

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		//a[i] = rand() % SIZE;
		v[i] = rand() % SIZE;
		d[i] = rand() % SIZE;
		//fl.push_front(rand() % SIZE);
		l.push_back(rand() % SIZE);
	}

	//printNonList("array", a, 42);
	printNonList("vector", v, 42);
	printNonList("deque", d, 42);
	//printList("flist", fl, 42);
	printList("list", l, 42);
	
	return (EXIT_SUCCESS);
}

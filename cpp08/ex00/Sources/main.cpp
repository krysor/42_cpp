#include "easyfind.hpp"
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <iostream>

#define SIZE 1000

int main( void ) {

	std::array<int, SIZE>	a;
	std::vector<int>		v(SIZE);
	std::deque<int>			d(SIZE);
	std::forward_list<int>	fl;
	std::list<int>			l;	

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		a[i] = i;
		v[i] = i;
		d[i] = i;
		fl.push_front(i);
		l.push_back(i);
	}
	a[SIZE / 4] = 42;
	v[SIZE / 3] = 42;
	d[SIZE / 2] = 42;
	fl.pop_front();
	fl.push_front(42);
	l.pop_back();
	l.push_back(42);

	std::cout << "number found:" << std::endl;
   
	std::cout << "array : " << easyfind(a, 42) - a.begin() << std::endl;
	std::cout << "vector: " << easyfind(v, 42) - v.begin() << std::endl;
	std::cout << "deque : " << easyfind(d, 42) - d.begin() << std::endl;
	std::cout << "flist : " << *easyfind(fl, 42) << std::endl;
	std::cout << "list  : " << *easyfind(l, 42) << std::endl;

	return (EXIT_SUCCESS);
}

#include "functions.hpp"

int main( void ) 
{
	Base*	ptr;
	
	srand(time(NULL));

	ptr = generate();
	identify(ptr);
	delete ptr;

	A		test;
	identify(test);

	return (0);
}

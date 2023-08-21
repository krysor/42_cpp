#include "functions.hpp"

int main( void ) 
{
	Base*	ptr;
	
	srand(time(NULL));

	ptr = generate();
	identify(ptr);
	delete ptr;

	A		test1;
	B		test2;
	C		test3;
	Base	test4;
	identify(test1);
	identify(test2);
	identify(test3);
	identify(test4);

	return (0);
}

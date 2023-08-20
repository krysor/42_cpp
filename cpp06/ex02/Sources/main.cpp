#include "functions.hpp"

int main( void ) 
{
	Base*	ptr;
	
	srand(time(NULL));

	ptr = generate();

	

	delete ptr;

	return (0);
}

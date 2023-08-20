#include "Serializer.hpp"

int main( void ) 
{
	Data		test;
	uintptr_t	raw;
	Data*		ptr;
	
	test.myNum = 42;
	test.myString = "Dziendobry";

	raw = Serializer::serialize(&test);
	ptr = Serializer::deserialize(raw);

	assert(ptr->myNum == 42);
	assert(ptr->myString == "Dziendobry");

	return (EXIT_SUCCESS);
}

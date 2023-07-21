#include "Animal.hpp"
#include "UI.hpp"

int main( void ) 
{
	Animal	animal1;
	Animal	animal2("dog");
	Animal	animal3(animal1);
	Animal	animal4 = animal2;

	//contructor test
	assert(animal1.getType().empty());
	assert(animal2.getType() == std::string("dog"));
	assert(animal3.getType().empty());
	assert(animal4.getType() == std::string("dog"));

	animal4.setType("cat");
	assert(animal4.getType() == std::string("cat"));

	return (EXIT_SUCCESS);
}
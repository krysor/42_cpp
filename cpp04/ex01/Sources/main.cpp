#include "Dog.hpp"
#include "Cat.hpp"
#include "UI.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main( void ) 
{
	//TEST Brain
	{
		std::string	arr[100];
		
		Brain	brain1;
		Brain	brain2(arr);
		Brain	brain3(brain1);
		Brain	brain4;

		brain4 = brain2;
	}

	return (EXIT_SUCCESS);
}

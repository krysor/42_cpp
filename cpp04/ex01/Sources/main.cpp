#include "Dog.hpp"
#include "Cat.hpp"
#include "UI.hpp"
#include "WrongCat.hpp"

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

	UI::printLine("\n");

	//TEST Cat
	{
		Cat	cat1;
		Cat	cat2("dog");
		Cat cat3(cat1);
		Cat	cat4;

		cat4 = cat2;
	}

	// UI::printLine("\n");

	// //TEST Dog
	// {
	// 	Dog	dog1;
	// 	Dog	dog2("dog");
	// 	Dog	dog3(dog1);
	// 	Dog	dog4;

	// 	dog4 = dog2;
	// }

	//system("leaks ex01");

	return (EXIT_SUCCESS);
}

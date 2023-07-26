#include "Dog.hpp"
#include "Cat.hpp"
#include "UI.hpp"
#include "WrongCat.hpp"

#define	ARRAYSIZE 4

int main( void ) 
{
	UI::printLine("\n");
	UI::printLine("Test [Brain]\n");
	{
		std::string	arr[100];
		
		Brain	brain1;
		Brain	brain2(arr);
		Brain	brain3(brain1);
		Brain	brain4;

		brain4 = brain2;
	}

	UI::printLine("\n");
	UI::printLine("Test [Cat]\n");
	{
		Cat	cat1;
		Cat	cat2("dog");
		Cat cat3(cat1);
		Cat	cat4;

		cat4 = cat2;
	}

	UI::printLine("\n");
	UI::printLine("Test [Dog]\n");
	{
		Dog	dog1;
		Dog	dog2("dog");
		Dog	dog3(dog1);
		Dog	dog4;

		dog4 = dog2;
	}

	UI::printLine("\n");
	UI::printLine("Test Subject\n");
	{
		//Create and fill an array of Animal objects
		Animal*			animals[ARRAYSIZE];
		unsigned int	i;
		
		//Half of it will be Dog object
		for (i = 0; i < ARRAYSIZE / 2 ; i++){
			animals[i] = new Dog();
		}

		//the other half will be Cat objects
		for (i = ARRAYSIZE / 2 ; i < ARRAYSIZE ; i++){
			animals[i] = new Cat();
		}

		//delete every Animal
		for (i = 0 ; i < ARRAYSIZE; i++){
			delete animals[i];
		}
	}

	UI::printLine("\n");
	UI::printLine("Test abstract class\n");
	{
		//Animal	animal;
	}

	UI::printLine("\n");
	system("leaks ex01");

	return (EXIT_SUCCESS);
}

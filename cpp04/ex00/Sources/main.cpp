#include "Dog.hpp"
#include "Cat.hpp"
#include "UI.hpp"
#include "WrongCat.hpp"

int main( void ) 
{
	//TEST Animal
	{
		Animal	animal1;
		Animal	animal2("dog");
		Animal	animal3(animal1);
		Animal	animal4;

		assert(animal1.getType().empty());
		assert(animal2.getType() == std::string("dog"));
		assert(animal3.getType().empty());
		assert(animal4.getType().empty());

		animal4 = animal2;
		assert(animal4.getType() == std::string("dog"));

		animal4.setType("cat");
		assert(animal4.getType() == std::string("cat"));
	}

	UI::printLine("\n");

	//TEST Dog
	{
		Dog	dog1;
		Dog dog2("cat");
		Dog dog3(dog1);
		Dog dog4;

		assert(dog1.getType() == std::string("Dog"));
		assert(dog2.getType() == std::string("Dog"));
		assert(dog3.getType() == std::string("Dog"));
		dog4 = dog2;
		assert(dog4.getType() == std::string("Dog"));
	}

	//TEST Cat
	{
		Cat	cat1;
		Cat cat2("dog");
		Cat cat3(cat1);
		Cat cat4 = cat2;

		assert(cat1.getType() == std::string("Cat"));
		assert(cat2.getType() == std::string("Cat"));
		assert(cat3.getType() == std::string("Cat"));
		assert(cat4.getType() == std::string("Cat"));
	}

	UI::printLine("\n");
	
	//subject main test
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	UI::printLine("\n");

	//subject main test: Animal and Cat replaced by WrongAnimal and WrongCat
	{
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	return (EXIT_SUCCESS);
}

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
	
// 	return 0;
// }
#include "Dog.hpp"
#include "UI.hpp"

Dog::Dog( void ) : _type("Dog")
{
	UI::printLine("[Dog] Default constructor called");
}

Dog::Dog( std::string type ) : _type("Dog")
{
	UI::printLine("[Dog] Name constructor called");
	(void)type;
}

Dog::Dog( const Dog& other ) : _type("Dog")
{
	UI::printLine("[Dog] Copy constructor called");
	setType(other.getType());
}

Dog&	Dog::operator=( const Dog& other )
{
	UI::printLine("[Dog] Copy assignment operator called");
	std::string	type;

	type = other.getType();
	setType(type);
	this->_type = "Dog";
	return (*this);
}

Dog::~Dog( void )
{
	UI::printLine("[Dog] Destructor called");
}

void	Dog::makeSound( void ) const
{
	UI::printLine("Woof! Woof!");
}
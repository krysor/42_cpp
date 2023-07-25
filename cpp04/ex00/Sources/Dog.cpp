#include "Dog.hpp"
#include "UI.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	UI::printLine("[Dog] Default constructor called");
	this->type = "Dog";
}

Dog::Dog( std::string type ) : Animal("Dog")
{
	(void)type;
	UI::printLine("[Dog] Name constructor called");
	this->type = "Dog";
}

Dog::Dog( const Dog& other ) : Animal("Dog")
{
	(void)other;
	UI::printLine("[Dog] Copy constructor called");
	this->type = "Dog";
}

Dog&	Dog::operator=( const Dog& other )
{
	(void)other;
	UI::printLine("[Dog] Copy assignment operator called");
	this->type = "Dog";
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

const std::string&	Dog::getType( void ) const
{
	return (this->type);
}

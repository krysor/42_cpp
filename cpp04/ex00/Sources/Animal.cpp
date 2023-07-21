#include "Animal.hpp"
#include "UI.hpp"

Animal::Animal( void )
{
	UI::printLine("Default constructor called");
}

Animal::Animal( std::string type )
{
	UI::printLine("Name constructor called");
	setType(type);
}

Animal::Animal( const Animal& animal )
{
	UI::printLine("Copy constructor called");
	operator=(animal);
}

Animal&	Animal::operator=( const Animal& other )
{
	UI::printLine("Copy assignment operator called");
	std::string	type;

	type = other.getType();
	setType(type);
	return (*this);
}

Animal::~Animal( void )
{
	UI::printLine("Destructor called");
}

const std::string&	Animal::getType( void ) const
{
	return (this->type);
}

void	Animal::setType( const std::string type )
{
	this->type = type;
}

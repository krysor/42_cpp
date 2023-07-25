#include "Animal.hpp"
#include "UI.hpp"

Animal::Animal( void )
{
	UI::printLine("[Animal] Default constructor called");
}

Animal::Animal( std::string type ) : type(type)
{
	UI::printLine("[Animal] Name constructor called");
}

Animal::Animal( const Animal& other ) : type(other.type)
{
	UI::printLine("[Animal] Copy constructor called");
}

Animal&	Animal::operator=( const Animal& other )
{
	UI::printLine("[Animal] Copy assignment operator called");
	this->type = other.getType();
	return (*this);
}

Animal::~Animal( void )
{
	UI::printLine("[Animal] Destructor called");
}

const std::string&	Animal::getType( void ) const
{
	return (this->type);
}

void	Animal::setType( const std::string type )
{
	this->type = type;
}

void	Animal::makeSound( void ) const
{
	UI::printLine("<Undefined animal sound>");
}
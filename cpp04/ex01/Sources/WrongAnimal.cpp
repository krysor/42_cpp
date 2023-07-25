#include "WrongAnimal.hpp"
#include "UI.hpp"

WrongAnimal::WrongAnimal( void )
{
	UI::printLine("[WrongAnimal] Default constructor called");
}

WrongAnimal::WrongAnimal( std::string type ) : type(type)
{
	UI::printLine("[WrongAnimal] Name constructor called");
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) : type(other.type)
{
	UI::printLine("[WrongAnimal] Copy constructor called");
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& other )
{
	UI::printLine("[WrongAnimal] Copy assignment operator called");
	this->type = other.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal( void )
{
	UI::printLine("[WrongAnimal] Destructor called");
}

const std::string&	WrongAnimal::getType( void ) const
{
	return (this->type);
}

void	WrongAnimal::setType( const std::string type )
{
	this->type = type;
}

void	WrongAnimal::makeSound( void ) const
{
	UI::printLine("[WrongAnimal]: <Undefined WrongAnimal sound>");
}
#include "Cat.hpp"
#include "UI.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	UI::printLine("[Cat] Default constructor called");
}

Cat::Cat( std::string type ) : Animal("Cat")
{
	UI::printLine("[Cat] Name constructor called");
	(void)type;
}

Cat::Cat( const Cat& other ) : Animal("Cat")
{
	UI::printLine("[Cat] Copy constructor called");
	(void)other;
}

Cat&	Cat::operator=( const Cat& other )
{
	UI::printLine("[Cat] Copy assignment operator called");
	std::string	type;

	type = other.getType();
	setType(type);
	this->_type = "Cat";
	return (*this);
}

Cat::~Cat( void )
{
	UI::printLine("[Cat] Destructor called");
}

void	Cat::makeSound( void ) const
{
	UI::printLine("Meeeeuuuuuuw!");
}
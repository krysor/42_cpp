#include "Cat.hpp"
#include "UI.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	UI::printLine("[Cat] Default constructor called");
	this->type = "Cat";
}

Cat::Cat( std::string type ) : Animal("Cat")
{
	(void)type;
	UI::printLine("[Cat] Name constructor called");
	this->type = "Cat";
}

Cat::Cat( const Cat& other ) : Animal("Cat")
{
	(void)other;
	UI::printLine("[Cat] Copy constructor called");
	this->type = "Cat";
}

Cat&	Cat::operator=( const Cat& other )
{
	(void)other;
	UI::printLine("[Cat] Copy assignment operator called");
	this->type = "Cat";
	return (*this);
}

Cat::~Cat( void )
{
	UI::printLine("[Cat] Destructor called");
}

void	Cat::makeSound( void ) const
{
	UI::printLine("[Cat]: Meeeeuuuuuuw!");
}

const std::string&	Cat::getType( void ) const
{
	return (this->type);
}

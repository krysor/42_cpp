#include "Cat.hpp"
#include "UI.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	UI::printLine("[Cat] Default constructor called");
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( std::string type ) : Animal("Cat")
{
	(void)type;
	UI::printLine("[Cat] Name constructor called");
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( const Cat& other ) : Animal("Cat")
{
	UI::printLine("[Cat] Copy constructor called");
	operator=(other);
}

Cat&	Cat::operator=( const Cat& other )
{
	UI::printLine("[Cat] Copy assignment operator called");
	delete this->_brain;
	this->type = "Cat";
	this->_brain = new Brain();
	this->_brain->setIdeas(other._brain->getIdeas());
	return (*this);
}

Cat::~Cat( void )
{
	UI::printLine("[Cat] Destructor called");
	delete this->_brain;
}

void	Cat::makeSound( void ) const
{
	UI::printLine("[Cat]: Meeeeuuuuuuw!");
}

const std::string&	Cat::getType( void ) const
{
	return (this->type);
}

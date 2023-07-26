#include "Dog.hpp"
#include "UI.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	UI::printLine("[Dog] Default constructor called");
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog( std::string type ) : Animal("Dog")
{
	(void)type;
	UI::printLine("[Dog] Name constructor called");
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog( const Dog& other ) : Animal("Dog")
{
	UI::printLine("[Dog] Copy constructor called");
	this->type = "Dog";
	this->_brain = new Brain();
	this->_brain->setIdeas(other._brain->getIdeas());
}

Dog&	Dog::operator=( const Dog& other )
{
	UI::printLine("[Dog] Copy assignment operator called");
	this->type = "Dog";
	delete this->_brain;
	this->_brain = new Brain();
	this->_brain->setIdeas(other._brain->getIdeas());
	return (*this);
}

Dog::~Dog( void )
{
	delete this->_brain;
	UI::printLine("[Dog] Destructor called");
}

void	Dog::makeSound( void ) const
{
	UI::printLine("[Dog]: Woof! Woof!");
}

const std::string&	Dog::getType( void ) const
{
	return (this->type);
}

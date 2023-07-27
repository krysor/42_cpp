#include "Ice.hpp"
#include "UI.hpp"

Ice::Ice( void ) : AMateria("ice")
{
	UI::printLine("[Ice] Default constructor called");
}

Ice::Ice( std::string const & type ) : AMateria("ice")
{
	UI::printLine("[Ice] Name constructor called");
	this->_type = type;
}

Ice::Ice( const Ice& other ) : AMateria("ice")
{
	UI::printLine("[Ice] Copy constructor called");
	this->_type = other._type;
}

Ice&	Ice::operator=( const Ice& other )
{
	(void)other;
	UI::printLine("[Ice] Copy assignment operator called");
	return (*this);
}

Ice::~Ice( void )
{
	UI::printLine("[Ice] Destructor called");
}

std::string const & Ice::getType() const
{
	return (this->_type);
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

void use(ICharacter& target)
{
	UI::printLine("* shoots an ice bolt at " + target.getName() + " *");
}

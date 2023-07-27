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
	UI::printLine("[Ice] Copy assignment operator called");
	this->_type = other._type;
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
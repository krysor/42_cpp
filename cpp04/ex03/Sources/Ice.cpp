#include "Ice.hpp"
#include "UI.hpp"

Ice::Ice( void ) : AMateria("ice")
{
	//UI::printLine("[Ice] Default constructor called");
	this->_type = "ice";
}

Ice::Ice( const Ice& other ) : AMateria("ice")
{
	(void)other;
	//UI::printLine("[Ice] Copy constructor called");
	this->_type = "ice";
}

Ice&	Ice::operator=( const Ice& other )
{
	(void)other;
	//UI::printLine("[Ice] Copy assignment operator called");
	return (*this);
}

Ice::~Ice( void )
{
	//UI::printLine("[Ice] Destructor called");
}

std::string const & Ice::getType() const
{
	return (this->_type);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	UI::printLine("* shoots an ice bolt at " + target.getName() + " *");
}

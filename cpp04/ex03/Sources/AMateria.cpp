#include "AMateria.hpp"
#include "UI.hpp"

AMateria::AMateria( void )
{
	UI::printLine("[AMateria] Default constructor called");
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
	UI::printLine("[AMateria] Name constructor called");
}

AMateria::AMateria( const AMateria& other ) : _type(other._type)
{
	UI::printLine("[AMateria] Copy constructor called");
}

AMateria&	AMateria::operator=( const AMateria& other )
{
	UI::printLine("[AMateria] Copy assignment operator called");
	this->_type = other._type;
	return (*this);
}

AMateria::~AMateria( void )
{
	UI::printLine("[AMateria] Destructor called");
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

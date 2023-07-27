#include "ICharacter.hpp"
#include "UI.hpp"

ICharacter::ICharacter( void )
{
	UI::printLine("[ICharacter] Default constructor called");
}

ICharacter::ICharacter( std::string const & type )
{
	UI::printLine("[ICharacter] Name constructor called");
	this->_type = type;
}

ICharacter::ICharacter( const ICharacter& other ) : AMateria("ICharacter")
{
	UI::printLine("[ICharacter] Copy constructor called");
	this->_type = other._type;
}

ICharacter&	ICharacter::operator=( const ICharacter& other )
{
	(void)other;
	UI::printLine("[ICharacter] Copy assignment operator called");
	return (*this);
}

ICharacter::~ICharacter( void )
{
	UI::printLine("[ICharacter] Destructor called");
}

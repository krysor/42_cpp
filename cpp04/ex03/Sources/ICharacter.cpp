#include "ICharacter.hpp"
#include "UI.hpp"

ICharacter::ICharacter( void )
{
	//UI::printLine("[ICharacter] Default constructor called");
}

ICharacter::ICharacter( const ICharacter& other )
{
	(void)other;
	//UI::printLine("[ICharacter] Copy constructor called");
}

ICharacter&	ICharacter::operator=( const ICharacter& other )
{
	(void)other;
	//UI::printLine("[ICharacter] Copy assignment operator called");
	return (*this);
}
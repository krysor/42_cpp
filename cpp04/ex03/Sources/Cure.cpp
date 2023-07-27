#include "Cure.hpp"
#include "UI.hpp"

Cure::Cure( void ) : AMateria("cure")
{
	UI::printLine("[Cure] Default constructor called");
}

Cure::Cure( std::string const & type ) : AMateria("cure")
{
	UI::printLine("[Cure] Name constructor called");
	this->_type = type;
}

Cure::Cure( const Cure& other ) : AMateria("cure")
{
	UI::printLine("[Cure] Copy constructor called");
	this->_type = other._type;
}

Cure&	Cure::operator=( const Cure& other )
{
	(void)other;
	UI::printLine("[Cure] Copy assignment operator called");
	return (*this);
}

Cure::~Cure( void )
{
	UI::printLine("[Cure] Destructor called");
}

std::string const & Cure::getType() const
{
	return (this->_type);
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

// void use(ICharacter& target)
// {
// 	UI::printLine("* heals " + <NAME> + "’s wounds *");
// }

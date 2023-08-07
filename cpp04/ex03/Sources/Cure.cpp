#include "Cure.hpp"
#include "UI.hpp"

Cure::Cure( void ) : AMateria("cure")
{
	UI::printLine("[Cure] Default constructor called");
	this->_type = "cure";
}

Cure::Cure( const Cure& other ) : AMateria("cure")
{
	(void)other;
	UI::printLine("[Cure] Copy constructor called");
	this->_type = "cure";
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

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	UI::printLine("* heals " + target.getName() + "’s wounds *");
}

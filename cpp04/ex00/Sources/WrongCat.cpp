#include "WrongCat.hpp"
#include "UI.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	UI::printLine("[WrongCat] Default constructor called");
	this->type = "WrongCat";
}

WrongCat::WrongCat( std::string type ) : WrongAnimal("WrongCat")
{
	(void)type;
	UI::printLine("[WrongCat] Name constructor called");
	this->type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal("WrongCat")
{
	(void)other;
	UI::printLine("[WrongCat] Copy constructor called");
	this->type = "WrongCat";
}

WrongCat&	WrongCat::operator=( const WrongCat& other )
{
	(void)other;
	UI::printLine("[WrongCat] Copy assignment operator called");
	this->type = "WrongCat";
	return (*this);
}

WrongCat::~WrongCat( void )
{
	UI::printLine("[WrongCat] Destructor called");
}

const std::string&	WrongCat::getType( void ) const
{
	return (this->type);
}

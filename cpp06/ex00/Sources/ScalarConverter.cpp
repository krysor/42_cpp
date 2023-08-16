#include "ScalarConverter.hpp"
#include "UI.hpp"

ScalarConverter::ScalarConverter( void )
{
	UI::printLine("[ScalarConverter] Default constructor called");
}

ScalarConverter::ScalarConverter( const ScalarConverter& other )
{
	(void)other;
	UI::printLine("[ScalarConverter] Copy constructor called");
}

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter& other )
{
	(void)other;
	UI::printLine("[ScalarConverter] Copy assignment operator called");
	return (*this);
}

ScalarConverter::~ScalarConverter( void )
{
	UI::printLine("[ScalarConverter] Destructor called");
}

void	ScalarConverter::convert( std::string literal )
{
	return ;
}
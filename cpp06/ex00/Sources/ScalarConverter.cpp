#include "ScalarConverter.hpp"
#include "isType.hpp"

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


void	ScalarConverter::convert( char *s )
{
	if (s == NULL || *s == '\0') {
		UI::printLine("The input string doesn't exist or is empty");
		return ;
	}
	if (isChar(s)) {
		UI::printLine("The input string is a char");
		//convert
		return ;
	}
	if (isInt(s)) {
		UI::printLine("The input string is an int");
		//convert
		return ;
	}
	if (isFloat(s)) {
		UI::printLine("The input string is a float");
		//convert
		return ;
	}
	if (isDouble(s)) {
		UI::printLine("The input string is a double");
		//convert
		return ;
	}
	UI::printLine("The input string is neither a char, an int, a float nor a double");
}
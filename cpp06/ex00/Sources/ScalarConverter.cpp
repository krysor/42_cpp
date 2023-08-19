#include "ScalarConverter.hpp"
#include "isType.hpp"
#include "printType.hpp"

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
	if (s == NULL || *s == '\0')
		UI::printLine("The input string doesn't exist or is empty");
	else if (isChar(s))
		printChar(*s);
	else if (isInt(s))
		printInt(std::atoi(s));
	else if (isFloat(s))
		printFloat(std::strtof(s, NULL));
	else if (isDouble(s))
		printDouble(std::strtod(s, NULL));
	else
		UI::printLine("The input string is neither a char, an int, a float nor a double");
}

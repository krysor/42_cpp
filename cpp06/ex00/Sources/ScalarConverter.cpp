#include "ScalarConverter.hpp"

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

bool	isChar( char *s )
{
	if (s[1] != '\0')
		return (false);
	if (s[0] < 32 || 126 < s[0])
		return (false);
	if ('0' <= s[0] && s[0] <= '9')
		return (false);
	return (true);
}

bool	isInt( char *s )
{
	(void)s;
	return (false);
}

bool	isFloat( char *s )
{
	(void)s;
	return (false);
}

bool	isDouble( char *s )
{
	(void)s;
	return (false);
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
	if (isInt(s))
		;
	if (isFloat(s))
		;
	if (isDouble(s))
		;
	UI::printLine("The input string is neither a char, an int, a float nor a double");
}
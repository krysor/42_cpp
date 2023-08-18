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

void	ScalarConverter::printChar( char c )
{
	std::cout << "char: " << "'" << c << "'" << std::endl; 
	std::cout << "int: " << "" << static_cast<int>(c) << "" << std::endl;
	std::cout << "float: " << "" << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << "" << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::printInt( int i )
{
	std::cout << "char: ";
	if (i < 32 || 126 < i)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl; 
	std::cout << "int: " << "" << i << "" << std::endl;
	std::cout << "float: " << "" << static_cast<int>(i) << ".0f" << std::endl;
	std::cout << "double: " << "" << static_cast<int>(i) << ".0" << std::endl;
}

void	ScalarConverter::convert( char *s )
{
	if (s == NULL || *s == '\0') {
		UI::printLine("The input string doesn't exist or is empty");
	}
	else if (isChar(s)) {
		UI::printLine("The input string is a char");
		printChar(*s);
	}
	else if (isInt(s)) {
		UI::printLine("The input string is an int");
		printInt(std::atoi(s));
	}
	else if (isFloat(s)) {
	
		UI::printLine("The input string is a float");
		//convert
		return ;
	}
	else if (isDouble(s)) {
		UI::printLine("The input string is a double");
		//convert
		return ;
	}
	else
		UI::printLine("The input string is neither a char, an int, a float nor a double");
}

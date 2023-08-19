#include "printType.hpp"
#include "UI.hpp"

void	printChar( char c )
{
	UI::printLine("The input string is a char");
	std::cout << "char: " << "'" << c << "'" << std::endl; 
	std::cout << "int: " << "" << static_cast<int>(c) << "" << std::endl;
	std::cout << "float: " << "" << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << "" << static_cast<double>(c) << ".0" << std::endl;
}

void	printInt( int i )
{
	UI::printLine("The input string is an int");
	std::cout << "char: ";
	if (i < 0 || i > 127)
		std::cout << "Impossible" << std::endl;
	else if (i < 32 || 126 < i)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << "" << i << "" << std::endl;
	std::cout << "float: " << "" << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << "" << static_cast<double>(i) << ".0" << std::endl;
}

void	printFloat( float f )
{
	UI::printLine("The input string is a float");
	
	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "Impossible" << std::endl;
	else if (f < 32 || 126 < f)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	
	std::cout << "int: ";
	if (f < INT_MIN || INT_MAX < f)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;

	std::cout << "float: " << "" << f << ".0f" << std::endl;
	std::cout << "double: " << "" << static_cast<double>(f) << ".0" << std::endl;
}

void	printDouble( double d )
{
	UI::printLine("The input string is a double");
	
	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "Impossible" << std::endl;
	else if (d < 32 || 126 < d)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	
	std::cout << "int: ";
	if (d < INT_MIN || INT_MAX < d)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: ";
	if (static_cast<double>(static_cast<float>(d)) != d)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << std::endl;
	
	std::cout << "double: " << "" << d << ".0" << std::endl;
}
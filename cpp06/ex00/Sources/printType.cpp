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
	std::cout << "float: " << "" << static_cast<int>(i) << ".0f" << std::endl;
	std::cout << "double: " << "" << static_cast<int>(i) << ".0" << std::endl;
}

void	printFloat( float f )
{
	UI::printLine("The input string is a float");
	(void)f;
	// std::cout << "char: ";
	// if (i < 0 || i > 127)
	// 	std::cout << "Impossible" << std::endl;
	// else if (i < 32 || 126 < i)
	// 	std::cout << "Non displayable" << std::endl;
	// else
	// 	std::cout << "'" << static_cast<char>(i) << "'" << std::endl; 
	// std::cout << "int: " << "" << i << "" << std::endl;
	// std::cout << "float: " << "" << static_cast<int>(i) << ".0f" << std::endl;
	// std::cout << "double: " << "" << static_cast<int>(i) << ".0" << std::endl;
}

void	printDouble( double d )
{
	UI::printLine("The input string is a double");
	(void)d;
	// std::cout << "char: ";
	// if (i < 0 || i > 127)
	// 	std::cout << "Impossible" << std::endl;
	// else if (i < 32 || 126 < i)
	// 	std::cout << "Non displayable" << std::endl;
	// else
	// 	std::cout << "'" << static_cast<char>(i) << "'" << std::endl; 
	// std::cout << "int: " << "" << i << "" << std::endl;
	// std::cout << "float: " << "" << static_cast<int>(i) << ".0f" << std::endl;
	// std::cout << "double: " << "" << static_cast<int>(i) << ".0" << std::endl;
}
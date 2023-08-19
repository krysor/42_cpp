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

	//print char
	std::cout << "char: ";
	if (i < 0 || i > 127)
		std::cout << "Impossible" << std::endl;
	else if (i < 32 || 126 < i)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	
	//print int
	std::cout << "int: " << "" << i << "" << std::endl;
	
	//print float
	std::cout << "float: " << static_cast<float>(i);
	if (-1000000 < i && i < 1000000)
		std::cout << ".0";
	std::cout << "f" <<  std::endl;
	
	//print double
	std::cout << "double: " << static_cast<double>(i);
	if (-1000000 < i && i < 1000000)
		std::cout << ".0";
	std::cout << std::endl;
}

void	printFloat( float f )
{
	UI::printLine("The input string is a float");
	
	//print char
	std::cout << "char: ";
	if (f < 0 || f > 127 || static_cast<float>(static_cast<char>(f)) != f)
		std::cout << "Impossible" << std::endl;
	else if (f < 32 || 126 < f)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	
	//print int
	std::cout << "int: ";
	if (f < INT_MIN || INT_MAX < f || static_cast<float>(static_cast<int>(f)) != f)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;

	//print float
	std::cout << "float: " << f;
	if (-1000000 < f && f < 1000000 && static_cast<float>(static_cast<int>(f)) == f)
		std::cout << ".0";
	std::cout << "f" <<  std::endl;

	//print double
	std::cout << "double: " << static_cast<double>(f);
	if (-1000000 < f && f < 1000000 && static_cast<float>(static_cast<int>(f)) == f)
		std::cout << ".0";
	std::cout << std::endl;
}

void	printDouble( double d )
{
	UI::printLine("The input string is a double");
	
	//print char
	std::cout << "char: ";
	if (d < 0 || d > 127 || static_cast<double>(static_cast<char>(d)) != d)
		std::cout << "Impossible" << std::endl;
	else if (d < 32 || 126 < d)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	
	//print int
	std::cout << "int: ";
	if (d < INT_MIN || INT_MAX < d || static_cast<double>(static_cast<int>(d)) != d)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	//print float
	std::cout << "float: ";
	if (static_cast<double>(static_cast<float>(d)) != d)
		std::cout << "Impossible" << std::endl;
	else {
		std::cout << static_cast<float>(d);
		if (-1000000 < d && d < 1000000 && static_cast<float>(static_cast<int>(d)) == d)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}

	//print double
	std::cout << "double: " << d;
	if (-1000000 < d && d < 1000000 && static_cast<double>(static_cast<int>(d)) == d)
		std::cout << ".0";
	std::cout << std::endl;
}

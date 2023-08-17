#include "ScalarConverter.hpp"

int main( int argc, char *argv[] ) 
{
	if (argc != 2) {
		UI::printLine("Please, provide exactly one input argument");
		return (EXIT_FAILURE);
	}
	
	
	
	
	ScalarConverter::convert(argv[1]);
	return (EXIT_SUCCESS);
}

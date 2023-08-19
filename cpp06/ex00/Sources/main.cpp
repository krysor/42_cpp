#include "ScalarConverter.hpp"

int main( int argc, char *argv[] ) 
{
	if (argc != 2) {
		UI::printLine("Please, provide exactly one input argument");
		return (EXIT_FAILURE);
	}
	
	//UI::printLine(std::to_string(123.123f));

	// std::string	test1 = "test";
	// std::string	test2 = "qwe";

	// UI::printLine(test1 < test2 ? "true" : "false");
	
	ScalarConverter::convert(argv[1]);
	return (EXIT_SUCCESS);
}

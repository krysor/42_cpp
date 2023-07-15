#include <iostream>
#include <iomanip>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string	&stringREF = str;

	int	width = 20;
	std::cout << std::left << std::setw(width) << "adress of str" << ": " << &str << std::endl;
	std::cout << std::left << std::setw(width) << "adress of stringPTR" << ": "<< stringPTR << std::endl;
	std::cout << std::left << std::setw(width) << "adress of stringREF" << ": "<< &stringREF << std::endl;

	std::cout << std::left << std::setw(width) << "str" << ": "<< str << std::endl;
	std::cout << std::left << std::setw(width) << "stringPTR" << ": "<< *stringPTR << std::endl;
	std::cout << std::left << std::setw(width) << "stringREF" << ": "<< stringREF << std::endl;
}
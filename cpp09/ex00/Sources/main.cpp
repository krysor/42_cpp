#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	std::ifstream					input;
	std::map<std::string, float>	dataBase;
	
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	if (extractDataBase(dataBase) == false)
		return (EXIT_FAILURE);
	input.open(argv[1], std::ios::in);
	if (input == NULL) {
		std::cout << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	input.close();
	//system("lsof -c ex04");
	return (EXIT_SUCCESS);
}

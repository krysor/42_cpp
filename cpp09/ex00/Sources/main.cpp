#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	data	dataBase;
	
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	if (extractData(dataBase, NAMEDATABASE) == false)
		return (EXIT_FAILURE);
	if (processInputFile(argv[1], dataBase) == false)
		return (EXIT_FAILURE);
	//system("lsof -c btc");
	return (EXIT_SUCCESS);
}

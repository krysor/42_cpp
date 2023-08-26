#include "BitcoinExchange.hpp"

bool	parseLine(std::string& line,
				  std::map<std::string, float>& dataBase)
{
	(void)line;
	(void)dataBase;
	return (true);
}

bool	extractDataBase( std::map<std::string, float>& dataBase )
{
	std::ifstream	streamDataBase;
	std::string		line;
	
	streamDataBase.open(NAMEDATABASE, std::ios::in);
	if (streamDataBase == NULL)
	{
		std::cout << "Error: could not open data.csv file." << std::endl;
		return (false);
	}
	while (std::getline(streamDataBase, line))
	{
		if (parseLine(line, dataBase) == false)
		{
			streamDataBase.close();
			return (false);
		}
	}
	streamDataBase.close();
	return (true);
}
#include "BitcoinExchange.hpp"

bool isLeapYear ( int year )
{
    if (year % 400 == 0 || 
		(year % 4 == 0 && year % 100 != 0))
        return (true);
    return (false);
}

bool	parseTime( struct tm* time )
{
	int	day;
	int	month;
	int	year;

	day = time->tm_mday;
	month = time->tm_mon;
	year = time->tm_year + 1900;
	if (day > 30 && (month == APRIL || month == JUNE
		|| month == SEPTEMBER || month == NOVEMBER))
		return (false);
	if (month == FEBRUARY)
	{
		if (day == 29 && isLeapYear(year))
			return (true);
		if (day > 28)
			return (false);
	}
	return (true);
}

bool	parseLineTime( std::string& lineTime, struct tm* time )
{
	char*		ptr;
	const char*	substr;

	substr = lineTime.c_str();	
	ptr = strptime(substr, "%Y-%m-%d", time);
	if (ptr == NULL)
		return (false);
	if (*ptr == '\0' && parseTime(time) == true)
		return (true);
	return (false);
}

bool	parseExchangeRate( double& exchangeRate )
{
	if (exchangeRate != exchangeRate)
		return (false);
	if (exchangeRate == +inf)
		return (false);
	if (exchangeRate < 0)
		return (false);
	return (true);
}

bool	parseLineExchangeRate( std::string& lineExchangeRate,
							   double& exchangeRate )
{
	char		*str_end;

	exchangeRate = std::strtod(lineExchangeRate, &str_end);
	if (*str_end == '\0' && parseExchangeRate(exchangeRate) == true)
		return (true);
	return (false);
}

bool	parseLine( std::string& line, dB& dataBase )
{
	struct tm	time;
	double		exchangeRate;
	size_t		indexComma;
	std::string	lineTime;
	
	indexComma = line.find(",", 0);
	lineTime = line.substr(0, indexComma);
	if (parseLineTime(lineTime, &time) == false)
		return (false);

	(void)dataBase;
	
	return (true);
}

bool	extractDataBase( dB& dataBase )
{
	std::ifstream	streamDataBase;
	std::string		line;
	
	streamDataBase.open(NAMEDATABASE, std::ios::in);
	if (streamDataBase == NULL)
	{
		std::cout << "Error: could not open "
				  << NAMEDATABASE << " file.\n";
		return (false);
	}
	while (std::getline(streamDataBase, line))
	{
		if (line == FIRSTLINEDATABASE)
			continue ;
		if (parseLine(line, dataBase) == false)
		{
			std::cout << "Error: " << NAMEDATABASE
					  << " file contains illegal line(s).\n";
			streamDataBase.close();
			return (false);
		}
	}
	streamDataBase.close();
	return (true);
}
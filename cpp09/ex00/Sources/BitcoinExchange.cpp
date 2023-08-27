#include "BitcoinExchange.hpp"

customTime::customTime( void ) {}

customTime::customTime( struct tm& time )
{
	this->time.tm_mday = time.tm_mday;
	this->time.tm_mon = time.tm_mon;
	this->time.tm_year = time.tm_year;
}

customTime::customTime( const customTime& other  )
{
	operator=(other);
}

customTime::~customTime( void ) {}

customTime& customTime::operator=( const customTime& other )
{
	this->time.tm_mday = other.time.tm_mday;
	this->time.tm_mon = other.time.tm_mon;
	this->time.tm_year = other.time.tm_year;
	return (*this);
}

bool	customTime::operator==( const customTime& other ) const
{
	if (this->time.tm_mday == other.time.tm_mday
	 && this->time.tm_mon == other.time.tm_mon
	 && this->time.tm_year == other.time.tm_year)
	 	return (true);
	return (false);
}

bool	customTime::operator <( const customTime& other ) const
{
	if (this->time.tm_year < other.time.tm_year
	 || (this->time.tm_year == other.time.tm_year
	  && this->time.tm_mon < other.time.tm_mon)
	 || (this->time.tm_year == other.time.tm_year
	  && this->time.tm_mon == other.time.tm_mon
	  && this->time.tm_mday < other.time.tm_mday))
	 	return (true);
	return (false);
}

bool	customTime::operator >( const customTime& other ) const
{
	if (operator==(other) == false && operator <(other) == false)
	 	return (true);
	return (false);
}

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
	if (exchangeRate == +INFINITY)
		return (false);
	if (exchangeRate < 0)
		return (false);
	return (true);
}

bool	parseLineExchangeRate( std::string& lineExchangeRate,
							   double& exchangeRate ) {
	const char*	str;
	char*		str_end;

	str = lineExchangeRate.c_str();
	exchangeRate = std::strtod(str, &str_end);
	if (*str_end == '\0' && parseExchangeRate(exchangeRate) == true)
		return (true);
	return (false);
}

bool	parseLine( std::string& line, dB& dataBase )
{
	size_t		indexComma;
	std::string	lineTime, lineExchangeRate;
	struct tm	time;
	double		exchangeRate;
	
	indexComma = line.find(",", 0);
	lineTime = line.substr(0, indexComma);
	if (parseLineTime(lineTime, &time) == false)
		return (false);
	lineExchangeRate = line.substr(indexComma + 1);
	if (parseLineExchangeRate(lineExchangeRate, exchangeRate) == false)
		return (false);
	if (dataBase.count(customTime(time)) != 0)
		return (false);
	dataBase[customTime(time)] = exchangeRate;
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
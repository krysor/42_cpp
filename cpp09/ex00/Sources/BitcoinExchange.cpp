#include "BitcoinExchange.hpp"

Date::Date( void ) {}

Date::Date( struct tm& date )
{
	this->date.tm_mday = date.tm_mday;
	this->date.tm_mon = date.tm_mon;
	this->date.tm_year = date.tm_year;
}

Date::Date( const Date& other  )
{
	operator=(other);
}

Date::~Date( void ) {}

Date& Date::operator=( const Date& other )
{
	this->date.tm_mday = other.date.tm_mday;
	this->date.tm_mon = other.date.tm_mon;
	this->date.tm_year = other.date.tm_year;
	return (*this);
}

bool	Date::operator==( const Date& other ) const
{
	if (this->date.tm_mday == other.date.tm_mday
	 && this->date.tm_mon == other.date.tm_mon
	 && this->date.tm_year == other.date.tm_year)
	 	return (true);
	return (false);
}

bool	Date::operator <( const Date& other ) const
{
	if (this->date.tm_year < other.date.tm_year
	 || (this->date.tm_year == other.date.tm_year
	  && this->date.tm_mon < other.date.tm_mon)
	 || (this->date.tm_year == other.date.tm_year
	  && this->date.tm_mon == other.date.tm_mon
	  && this->date.tm_mday < other.date.tm_mday))
	 	return (true);
	return (false);
}

bool	Date::operator >( const Date& other ) const
{
	if (operator==(other) == false && operator <(other) == false)
	 	return (true);
	return (false);
}

bool	Date::operator>=( const Date& other ) const
{
	if (operator==(other) == true || operator >(other) == true)
	 	return (true);
	return (false);
}

bool	Date::operator<=( const Date& other ) const
{
	if (operator==(other) == true || operator <(other) == true)
	 	return (true);
	return (false);
}

const Date&	Date::operator--( void )
{
	if (this->date.tm_mday > 1)
	{
		this->date.tm_mday--;
		return (*this);
	}
	if (this->date.tm_mon > 0)
	{
		this->date.tm_mday = 31;
		this->date.tm_mon--;
		return (*this);
	}
	if (this->date.tm_year > 1)
	{
		this->date.tm_year--;
		this->date.tm_mon = 11;
		this->date.tm_mday = 31;
		return (*this);
	}
	return (*this);
}

struct tm& Date::getDate( void )
{
	return (this->date);
}

bool isLeapYear ( int year )
{
    if (year % 400 == 0 || 
		(year % 4 == 0 && year % 100 != 0))
        return (true);
    return (false);
}

bool	parseDate( struct tm* date )
{
	int	day;
	int	month;
	int	year;

	day = date->tm_mday;
	month = date->tm_mon;
	year = date->tm_year;
	if (day > 30 && (month == APRIL || month == JUNE
		|| month == SEPTEMBER || month == NOVEMBER))
		return (false);
	if (month == FEBRUARY)
	{
		if (day == 29 && isLeapYear(year + 1900))
			return (true);
		if (day > 28)
			return (false);
	}
	return (true);
}

bool	parseLineDate( std::string& lineDate, struct tm* date )
{
	char*		ptr;
	const char*	substr;

	substr = lineDate.c_str();	
	ptr = strptime(substr, "%Y-%m-%d", date);
	if (ptr == NULL)
		return (false);
	if (*ptr == '\0' && parseDate(date) == true)
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

bool	parseLine( std::string& line, data& dataBase )
{
	size_t		indexComma;
	std::string	lineDate, lineExchangeRate;
	struct tm	date;
	double		exchangeRate;
	
	if (line == FIRSTLINEDATABASE)
		return (true);
	indexComma = line.find(",", 0);
	if (indexComma == std::string::npos)
		return (false);
	lineDate = line.substr(0, indexComma);
	if (parseLineDate(lineDate, &date) == false)
		return (false);
	lineExchangeRate = line.substr(indexComma + 1);
	if (parseLineExchangeRate(lineExchangeRate, exchangeRate) == false)
		return (false);
	if (dataBase.count(Date(date)) != 0)
		return (false);
	dataBase[Date(date)] = exchangeRate;
	return (true);
}

bool	extractData( data& dataBase, const char* nameFile )
{
	std::ifstream	streamDataBase;
	std::string		line;
	
	streamDataBase.open(nameFile, std::ios::in);
	if (streamDataBase == NULL)
	{
		std::cout << "Error: could not open "
				  << nameFile << " file.\n";
		return (false);
	}
	while (std::getline(streamDataBase, line))
	{
		if (parseLine(line, dataBase) == false)
		{
			std::cout << "Error: " << nameFile
					  << " file contains illegal line(s).\n";
			streamDataBase.close();
			return (false);
		}
	}
	streamDataBase.close();
	return (true);
}

bool	parseValue( double& value )
{
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

bool	parseLineValue( std::string& lineValue, double& value )
{
	const char*	str;
	char*		str_end;

	if (lineValue.empty())
	{
		std::cout << "Error: no value provided as input" << std::endl;
		return (false);
	}
	str = lineValue.c_str();
	value = std::strtod(str, &str_end);
	if (*str_end != '\0')
	{
		std::cout << "Error: bad input => " << lineValue << std::endl;
		return (false);
	}
	if (*str_end == '\0' && parseValue(value) == true)
		return (true);
	return (false);
}

double	getResult( Date date, double& value, data& dataBase )
{	
	while (date >= dataBase.begin()->first)
	{
		while (parseDate(&date.getDate()) == false) {
			--date;
		}
		if (dataBase.count(date) == 1)
			return (value * dataBase[date]);	
		--date;
	}
	return (-1);
}

void	processLine( std::string& line, data& dataBase )
{
	size_t		indexSeparator;
	std::string	lineDate, lineValue;
	struct tm	date;
	double		value, result;
	
	indexSeparator = line.find(SEPARATORINPUTFILE, 0);
	if (indexSeparator == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	lineDate = line.substr(0, indexSeparator);
	if (parseLineDate(lineDate, &date) == false)
	{
		std::cout << "Error: bad date => " << lineDate << std::endl;
		return ;
	}
	lineValue = line.substr(indexSeparator + strlen(SEPARATORINPUTFILE));
	if (parseLineValue(lineValue, value) == false)
		return ;
	result = getResult(Date(date), value, dataBase);
	if (result < 0)
	{
		std::cout << "Error: no date found before the date => " << lineDate << std::endl;
		return ;
	}
	std::cout << lineDate
			  << " => "
			  << lineValue
			  << " = "
			  << std::setprecision (2) << std::fixed
			  << result
			  << std::endl;
}

bool	processInputFile( const char* nameFile, data& dataBase )
{
	std::ifstream	streamInputFile;
	std::string		line;
	bool			firstLine;
	
	streamInputFile.open(nameFile, std::ios::in);
	if (streamInputFile == NULL)
	{
		std::cout << "Error: could not open "
				  << nameFile << " file.\n";
		return (false);
	}
	firstLine = true;
	while (std::getline(streamInputFile, line))
	{
		if (firstLine == true)
		{
			firstLine = false;
			if (line == FIRSTLINEINPUTFILE)
				continue ;
			std::cout << "Error: first line not equal to \""
					  << FIRSTLINEINPUTFILE << "\"" << std::endl;
			return (false);
		}
		if (line.empty() == true)
			continue ;
		processLine(line, dataBase);
	}
	streamInputFile.close();
	return (true);
}

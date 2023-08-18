#include "isType.hpp"

bool	isChar( char *s )
{
	if (s[1] != '\0')
		return (false);
	if (s[0] < 32 || 126 < s[0])
		return (false);
	if ('0' <= s[0] && s[0] <= '9')
		return (false);
	return (true);
}

bool	isInt( char *s )
{
	unsigned int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i]) {
		if (s[i] < '0' || '9' < s[i])
			return (false);
		i++;
	}
	return (true);
}

bool	isFloat( char *s )
{
	std::string		str;
	bool			dot;
	bool			f;
	unsigned int	i;

	str += s;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	dot = false;
	f = false;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i]) {
		if (s[i] == '.' && dot == false)
			dot = true;
		else if (s[i] == '.' && dot == true) 
			return (false);
		else if (s[i] == 'f' && f == false)
			f = true;
		else if (s[i] == 'f' && f == true )
			return (false);
		else if (s[i] < '0' || '9' < s[i])
			return (false);
		i++;
	}
	if (dot == true && f == true)
		return (true);
	return (false);
}

bool	isDouble( char *s )
{
	std::string		str;
	unsigned int	i;
	bool			dot;

	str += s;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	dot = false;
	while (s[i]) {
		if (s[i] == '.' && dot == false)
			dot = true;
		else if (s[i] == '.' && dot == true) 
			return (false);
		else if (s[i] < '0' || '9' < s[i])
			return (false);
		i++;
	}
	if (dot == true)
		return (true);
	return (false);
}

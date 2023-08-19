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
	bool			sign;
	unsigned int	i;
	std::string		str;

	sign = false;
	i = 0;
	if (s[i] == '+' || s[i] == '-') {
		sign = true;
		i++;
	}
	while (s[i]) {
		if (s[i] < '0' || '9' < s[i])
			return (false);
		i++;
	}
	if ((sign == false && i > 10) || (sign == true && i > 11))
		return (false);
	if ((sign == false && i == 10) || (sign == true && i == 11)) {
		if (s[0] == '+' && str + s > str + "+2147483647")
			return (false);
		else if (s[0] == '-' && str + s > str + "-2147483648")
			return (false);
		else if (str + s  > str + "2147483647")
			return (false);
	}
	return (true);
}

bool	isFloat( char *s )
{
	std::string		str;
	bool			dot;
	bool			f;
	bool			sign;
	// bool			zero;
	unsigned int	i;

	str += s;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	dot = false;
	f = false;
	sign = false;
	// zero = false;
	i = 0;
	if (s[i] == '+' || s[i] == '-') {
		sign = true;
		i++;
	}
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

		// else if (s[i] == '0')
		// else if ('1' <= s[i] || s[i] <= '9')
		// 	zero = true;
		
		i++;
	}
	if (dot == true && f == true
		&& ((sign == true && i > 3) || (sign == false && i > 2)))
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

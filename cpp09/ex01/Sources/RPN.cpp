#include "RPN.hpp"

bool	calculate( char c, std::stack<long>& stack )
{
	long	x;
	long	y;

	if (stack.size() < 2)
	{
		std::cout << ERRSTACKSIZE;
		return (false);
	}
	y = stack.top();
	stack.pop();
	x = stack.top();
	stack.pop();
	if (c == '+')
		stack.push(x + y);
	else if (c == '-')
		stack.push(x - y);
	else if (c == '*')
		stack.push(x * y);
	else if (c == '/')
	{
		if (y == 0)
		{
			std::cout << ERRZERO;
			return (false);
		}
		stack.push(x / y);
	}
	return (true);
}
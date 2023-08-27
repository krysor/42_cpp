#include "RPN.hpp"

int	printErrMsg( const char* msg )
{
	std::cerr << msg;
	return (EXIT_FAILURE);
}

int	operation( char c, std::stack<long>& stack )
{
	long	x;
	long	y;

	if (stack.size() < 2)
		return (printErrMsg(ERRSTACKSIZE));
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
			return (printErrMsg(ERRZERO));
		stack.push(x / y);
	}
	return (EXIT_SUCCESS);
}
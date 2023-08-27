#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	std::stack<long>	stack;
	char*				ptr;
	
	if (argc != 2)
	{
		std::cout << ERRARGC;
		return (EXIT_FAILURE);
	}
	ptr = argv[1];
	while (*ptr)
	{
		if (*ptr == ' ')
		{
			ptr++;
			argv[1]++;
			continue ;
		}
		if (*ptr == '+' || *ptr == '-'
		 || *ptr == '*' || *ptr == '/')
		{
			if (calculate(*ptr, stack) == false)
				return (EXIT_FAILURE);
			ptr++;
			continue ;
		}
		stack.push(strtol(argv[1], &ptr, 10));
		if (*ptr != ' ' && *ptr != '\0')
		{
			std::cout << ERRINPUT;
			return (EXIT_FAILURE);
		}
		argv[1] += ptr - argv[1];
	}
	if (stack.size() != 1)
	{
		std::cout << ERREND;
		return (EXIT_FAILURE);
	}
	std::cout << stack.top() << std::endl;
	return (EXIT_SUCCESS);
}

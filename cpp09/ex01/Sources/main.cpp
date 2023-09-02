#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	std::stack<long>	stack;
	char*				ptr;
	
	if (argc != 2)
		return (printErrMsg(ERRARGC));
	while (*argv[1])
	{
		if (*argv[1] == ' ')
			argv[1]++;
		else if (isOperator(argv[1]) == true)
		{
			if (operation(*argv[1], stack) == FAILED)
				return (EXIT_FAILURE);
			argv[1]++;
		}
		else
		{
			stack.push(strtol(argv[1], &ptr, 10));
			if (*ptr != ' ' && *ptr != '\0')
				return (printErrMsg(ERRINPUT));
			if (stack.top() >= 10)
				return (printErrMsg(ERRVAL));
			argv[1] = ptr;
		}
	}
	if (stack.size() != 1)
		return (printErrMsg(ERREND));
	std::cout << stack.top() << std::endl;
	return (EXIT_SUCCESS);
}

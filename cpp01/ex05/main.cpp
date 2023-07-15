#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl			harl;
	std::string		levels[]	=	{"DEBUG", "INFO", "WARNING", "ERROR", "qwerty", ""};
	int				i			= 	-1;

	while (!levels[++i].empty())
		harl.complain(levels[i]);
	return (EXIT_SUCCESS);
}

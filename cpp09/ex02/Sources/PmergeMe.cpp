#include "PmergeMe.hpp"

int	printMsg( const char* msg, int exitCode )
{
	std::cerr << msg;
	return (exitCode);
}
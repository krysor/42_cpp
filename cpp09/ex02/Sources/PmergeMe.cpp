#include "PmergeMe.hpp"

int	printMsg( const char* msg, int exitCode )
{
	std::cerr << msg;
	return (exitCode);
}

void	printInt( long i )
{
	std::cout << i;
	std::cout << " ";
}

void	printResult( size_t			size,
					 const char*	name, 
					 double 		time )
{
	std::cout << "Time to process a range of "
			  << size
			  << " elements with std::"
			  << std::setw(6) << std::left
			  << name
			  << " : "
			  << time
			  << " us"
			  << std::endl;
}

unsigned long	getGroupSize( unsigned long iGroup )
{
	if (iGroup == 0 || iGroup == 1)
		return (2);
	return (pow(2, iGroup) + getGroupSize(iGroup - 2));
}

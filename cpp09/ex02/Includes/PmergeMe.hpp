#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>

#include <vector>
#include <deque>

#include <sys/time.h>

#define	SUCCESS	true
#define	FAILURE	false

#define ERRARGC		"Error: provide at least 2 arguments\n"
#define ERRSORTED	"Error: the arguments are already sorted\n"

#define	BASE		10

int		printMsg( const char* msg, int exitCode );
void	printInt( long i );

template <typename T>
void	printContainer( T& container, const char* msg )
{
	std::cout << std::setw(6) << std::left << msg << ":  ";
	for_each(container.begin(), container.end(), &printInt);
	std::cout << std::endl;
}

template <typename T>
bool	fillContainer( T& container, char *argv[] )
{
	long	l;
	char*	ptr;
	
	while (*(++argv))
	{
		l = strtol(*argv, &ptr, BASE);
		if (l < 0 || *ptr != '\0')
			return (FAILURE);
		container.push_back(l);
	}
	return (SUCCESS);
}

// template <typename T>
// bool	isSorted(T& container)
// {
// 	for (typename T::iterator it = container.begin();
// 		 it + 1 != container.end(); it++)
// 	{
// 		if (*it > *(it + 1))
// 			return (false);
// 	}
// 	return (true);
// }

#endif

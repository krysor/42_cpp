#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

#define ERRARGC		"Error: provide at least 2 arguments\n"
#define ERRSORTED	"Error: the arguments are already sorted\n"

#define	BASE	10

int		printMsg( const char* msg, int exitCode );

template <typename T>
bool	isSorted(T& container)
{
	for (typename T::iterator it = container.begin();
		 it + 1 != container.end(); it++)
	{
		if (*it > *(it + 1))
			return (false);
	}
	return (true);
}

#endif

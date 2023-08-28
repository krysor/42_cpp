#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sys/time.h>

#include <vector>
#include <deque>

#define	SUCCESS		true
#define	FAILURE		false

#define ERRARGC		"Error: provide at least 2 arguments\n"
#define ERRSORTED	"Error: the arguments are already sorted\n"

#define	BASE		10

int		printMsg( const char*	msg,
				  int 			exitCode );
void	printInt( long i );
void	printResult( size_t 		size,
					 const char*	name,
					 double 		time );

template <typename T>
void	printContainer( T& container, const char* msg )
{
	std::cout << std::setw(6)
			  << std::left
			  << msg
			  << ":  ";
	for_each(container.begin(),
			 container.end(),
			 &printInt);
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

template <typename T>
double	timeContainer(T& container, char *argv[])
{
	struct timeval t1, t2;
	double elapsedTime;
	
	gettimeofday(&t1, NULL);

	fillContainer(container, argv);

	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000000;
    elapsedTime += (t2.tv_usec - t1.tv_usec);
	return (elapsedTime);
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

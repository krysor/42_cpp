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
#define	ERRDUPL		"Error: the list of arguments has duplicates\n"

#define	BASE		10
#define NOT			-1

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
bool	containsDuplicates( T& container )
{
	for (typename T::iterator it = container.begin();
		 it + 1 != container.end(); it++)
	{
		if (*it == *(it + 1))
			return (true);
	}
	return (false);
}

template <typename T>
void	comparePairs( T& container, T& other )
{
	typename T::iterator	it;

	it = container.begin();
	while (it != container.end() && it + 1 != container.end())
	{
		if (*it > *(it + 1))
		{
			other.push_back(*(it + 1));
			it = container.erase(it + 1);
		}
		else
		{
			other.push_back(*it);
			it = container.erase(it) + 1;
		}
	}
}

template <typename T>
void	insertSingle( T& container, T& other, long single )
{
	if (single > *container.begin())
		container.push_back(single);
	else if (single  > *other.begin())
		other.push_back(single);
	else
		other.insert(other.begin(), single);
	while (other.size() > 0)
	{
		container.insert(container.begin(), *other.begin());
		other.erase(other.begin());
	}
}

template <typename T>
T	sortContainer( T& container )
{
	T		other;
	T		otherOld;
	T		containerOld;
	long	single = NOT;
	
	comparePairs(container, other);
	if (other.size() < container.size())
	{
		single = *(container.end() - 1);
		container.erase(container.end() - 1);
	}
	otherOld = other;
	containerOld = container;

	std::cout << "before if" << std::endl;
	for_each(container.begin(), container.end(), &printInt);
	std::cout << std::endl;
	for_each(other.begin(), other.end(), &printInt);
	std::cout << std::endl;
	std::cout << std::endl;

	if (container.size() == 1)
	{
		if (single == NOT)
			container.insert(container.begin(), *other.begin());
		else
			insertSingle(container, other, single);
		return (container);
	}	
	else
		container = sortContainer(container);
	//imagine container sorted now

	std::cout << "after if" << std::endl;
	for_each(container.begin(), container.end(), &printInt);
	std::cout << std::endl;
	for_each(other.begin(), other.end(), &printInt);
	std::cout << std::endl;
	std::cout << std::endl;

	return (container);
}

template <typename T>
double	timeContainer( T& container, char *argv[] )
{
	struct timeval t1, t2;
	double elapsedTime;
	
	gettimeofday(&t1, NULL);
	fillContainer(container, argv);

	container = sortContainer(container);
	
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000000;
    elapsedTime += (t2.tv_usec - t1.tv_usec);
	return (elapsedTime);
}

#endif

/*
template <typename T>
void	sortContainer( T& container )
{
	typename T::iterator	it;

	//T						containerOld;
	T						other;
	//T						otherOld;
	long					uneven = -1;
	
	it = container.begin();
	while (it != container.end() && it + 1 != container.end())
	{
		if (*it > *(it + 1))
		{
			other.push_back(*(it + 1));
			it = container.erase(it + 1);
		}
		else
		{
			other.push_back(*it);
			it = container.erase(it) + 1;
		}
	}
	if (other.size() < container.size())
	{
		uneven = *(container.end() - 1);
		container.erase(container.end() - 1);
	}

	//imagine container sorted now



	for_each(container.begin(), container.end(), &printInt);
	std::cout << std::endl;
	for_each(other.begin(), other.end(), &printInt);
	std::cout << std::endl;
	return ;
}
*/
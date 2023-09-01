#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sys/time.h>
#include <vector>
#include <deque>

#define RESET	std::string("\33[0m")
#define RED		std::string("\33[31m")
#define GREEN	std::string("\33[32m")
#define YELLOW	std::string("\33[33m")
#define BLUE	std::string("\33[34m")

#define	SUCCESS		true
#define	FAILURE		false

#define ERRARGC		"Error: provide at least 2 arguments\n"
#define ERRSORTED	"Error: the arguments are already sorted\n"
#define	ERRDUPL		"Error: the list of arguments has duplicates\n"

#define	BASE		10
#define NOT			-1

struct Data {
  
  long	main;
  long	side;

};

int		printMsg( const char*	msg,
				  int 			exitCode );
void	printInt( long i );
void	printResult( size_t 		size,
					 const char*	name,
					 double 		time );
long	getGroupSize( unsigned long iGroup );

template <typename T>
void	printNthRow( T& matrix, unsigned long n )
{
	if (matrix.front().size() <= n)
		return ;
	for (unsigned int l = 0; l < matrix.size(); l++)
		std::cout << matrix.at(l).at(n) << " ";
	std::cout << std::endl;
}

template <typename T>
bool	fillContainer( T& container, char *argv[] )
{
	long		l;
	char*		ptr;
	
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
void	printContainer( T& container,
						const char* msg )
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
bool	hasDuplicates( T& container )
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
void	transpose( T& matrix )
{	
	long					nb;
	unsigned int			i;

	i = matrix.front().size() - 1;
	while (matrix.front().size() > 1)
	{
		nb = matrix.front().back();
		matrix.at(i).push_back(nb);
		matrix.front().pop_back();
		i--;
	}
}

template <typename T>
void	comparePairs( T& container )
{
	typename T::iterator	it;

	it = container.begin();
	while (it != container.end() && (it + 1) != container.end())
	{
		if ( *((*it).begin()) > *((*(it + 1)).begin()) )
		{
			(*it).insert((*it).end(), (*(it + 1)).begin(), (*(it + 1)).end());
			it = container.erase(it + 1);
		}
		else
		{
			(*(it + 1)).insert((*(it + 1)).end(), (*it).begin(), (*it).end());
			it = container.erase(it) + 1;
		}
	}
}

template <typename T>
void	createSideChain( T& matrix, T& sideChain )
{
	unsigned long	l;
	unsigned long	halfColumnSize;

	halfColumnSize = matrix.at(0).size() / 2;
	l = -1;
	while (++l < matrix.size())
	{
		sideChain.at(l).insert(sideChain.at(l).end(),
							   matrix.at(l).begin() + halfColumnSize,
							   matrix.at(l).end());
		matrix.at(l).erase(matrix.at(l).begin() + halfColumnSize,
						   matrix.at(l).end());
	}
}

template <typename T>
void	fillSideChain( T& mainChain, T& sideChain, T& single)
{
	if (mainChain.front().size() > 1 && mainChain.front().size() != single.front().size())// && mainChain.size() > 2 instead of the second condition)
		createSideChain(mainChain, sideChain);
	if (sideChain.front().size() > 0)
	{
		mainChain.insert(mainChain.begin(), sideChain.front());
		sideChain.erase(sideChain.begin());
	}
	if (single.front().size() > 0)
	{
		if (sideChain.front().size() == 0)
			sideChain = single;
		else
			sideChain.insert(sideChain.end(), single.front());
	}
}

template <typename T>
unsigned long	binarySearch( T& mainChain,
							  long value,
							  unsigned long start,
							  unsigned long end )
{
	unsigned long	mid;

	if (start >= end)
		return (end);//before start
	mid = start + (end - start) / 2;
	if (value < mainChain.at(mid).front())
		return (binarySearch(mainChain, value, start, mid));
	else
		return (binarySearch(mainChain, value, mid + 1, end));
}

template <typename T>
void	binaryInsertion( T& mainChain, T& single )
{
	T		sideChain(mainChain.size());
	long	iGroup, iSide, iMain;

	fillSideChain(mainChain, sideChain, single);
	iGroup = 0;
	while (sideChain.size() > 0)
	{
		iSide = getGroupSize(iGroup) - 1;
		if (sideChain.size() - 1 < (unsigned long)iSide)
			iSide = sideChain.size() - 1;
		while (iSide >= 0)
		{
			iMain = binarySearch(mainChain,
								 sideChain.at(iSide).front(),
								 0,
								 mainChain.size());//cahnged from mainChain.size() - 1
			mainChain.insert(mainChain.begin() + iMain,
							 sideChain.at(iSide));
			sideChain.erase(sideChain.begin() + iSide);
			iSide--;
		}
		iGroup++;
	}
}

template <typename T>
T	mergeInsertion( T& matrix )
{
	T	single(1);

	if (matrix.size() == 1)
		return (matrix);
	if (matrix.size() == 2)
	{
		if (matrix.at(0).front() > matrix.at(1).front())
			matrix.front().swap(matrix.at(1));
		return (matrix);
	}
	if (matrix.size() % 2 == 1)
	{
		single.front().insert(single.front().end(), matrix.back().begin(), matrix.back().end());
		matrix.pop_back();
	}
	if (matrix.size() > 2)
		comparePairs(matrix);
	matrix = mergeInsertion(matrix);
	if (matrix.front().size() != 1 || single.front().size() != 0)
		binaryInsertion(matrix, single);
	return (matrix);
}

template <typename T>
double	timeContainer( T& matrix, char *argv[] )
{
	struct timeval t1, t2;
	double elapsedTime;
	
	gettimeofday(&t1, NULL);
	fillContainer(*matrix.begin(), argv);
	transpose(matrix);
	matrix = mergeInsertion(matrix);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000000;
    elapsedTime += (t2.tv_usec - t1.tv_usec);
	return (elapsedTime);
}

template <typename T>
bool	isSorted( T& matrix )
{
	for (typename T::iterator it = matrix.begin();
		 it + 1 != matrix.end(); it++)
	{
		if (*(*it).begin() > *((*(it + 1)).begin()))
			return (false);
	}
	return (true);
}

#endif

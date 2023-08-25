#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <vector>
#include <iterator>
#include <string>
#include <iostream>

#define RESET	std::string("\33[0m")
#define RED		std::string("\33[31m")
#define GREEN	std::string("\33[32m")
#define YELLOW	std::string("\33[33m")
#define BLUE	std::string("\33[34m")

class Span {

private:
	
		std::vector<int>	integers;
		unsigned int		size;

public:
	
	Span( void );
	Span( unsigned int n );
	Span( const Span& other );
	Span&	operator=( const Span& other );
	~Span( void );

	void	addNumber( int nb );

	void	addRange(std::vector<int>::iterator  start,
					 std::vector<int>::iterator end);
	
	class SpanFull : public std::exception {
		const char* what() const throw();
	};

	class LongestSpan : public std::exception {
		const char* what() const throw();
	};

	class ShortestSpan : public std::exception {
		const char* what() const throw();
	};

	unsigned int	shortestSpan( void ) const;
	unsigned int	longestSpan( void ) const;
};

void	printLine( std::string line );

#endif

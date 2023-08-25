#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <vector>
#include <iterator>
#include "UI.hpp"

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


#endif

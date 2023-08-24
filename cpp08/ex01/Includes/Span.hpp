#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <vector>
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
	
	class SpanFull : public std::exception {
		const char* what() const throw();
	};

	class longestSpan : public std::exception {
		const char* what() const throw();
	};

	class shortestSpan : public std::exception {
		const char* what() const throw();
	};

	unsigned int	shortestSpan( void ) const;
	unsigned int	longestSpan( void ) const;
};


#endif

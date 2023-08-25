#pragma once
#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <vector>
#include <iterator>
#include "UI.hpp"

template<class T> 
class MutantStack {

private:
	
		std::vector<T>		stack;

public:
	
	MutantStack( void );
	explicit MutantStack( const Container& cont = Container() );
	MutantStack( const MutantStack& other );
	MutantStack&	operator=( const MutantStack& other );
	~MutantStack( void );

	T&					top( void ) const;
	bool				empty( void ) const;
	unsigned long int	size( void ) const;
	void				push( const T& value );
	void				pop( void );
		
};


#endif

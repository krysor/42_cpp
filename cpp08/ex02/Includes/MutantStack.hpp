#pragma once
#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <stack>
#include <deque>

template<class T> 
class MutantStack : public std::stack<T> {

public:
	
	MutantStack( void ) : std::stack<T>() {}
	MutantStack( const MutantStack& other ) : std::stack<T>(other) {}
	~MutantStack( void ) {}
	MutantStack& operator=( const MutantStack& other ) {
		*this = other;
		return *this;
	}
	
	typedef typename std::deque<T>::iterator	iterator;

	iterator	begin( void )	{ return this->c.begin(); }
	iterator	end( void )		{ return this->c.end()  ; }

};

#endif
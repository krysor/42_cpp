#pragma once
#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <vector>

template<class T> 
class MutantStack {

private:
	
	std::vector<T>	stack;

public:
	
	MutantStack( void )						: stack(0) 				{}
	MutantStack( const MutantStack& other ) : stack(other.stack)	{}
	~MutantStack( void )											{}
	MutantStack&	operator=( const MutantStack& other ) {
		stack = other.stack;
		return (*this);
	}

	T&		top( void )		const	{ return *stack.end()			; }
	bool	empty( void )	const	{ return !size() ? true : false	; }
	size_t	size( void )	const	{ return stack.size()			; }
	void	push( const T& value )	{ stack.push_back(value)		; }
	void	pop( void )				{ stack.pop_back()				; }

};


#endif

#include "MutantStack.hpp"

MutantStack::MutantStack( void ) : stack(0)
{
	//UI::printLine("[MutantStack] Default constructor called");
}

explicit MutantStack::MutantStack( const Container& cont = Container() ) : integers(0), size(n)
{
	//UI::printLine("[MutantStack] Default constructor called");

	//TOOOOODOOOOOOO
}

MutantStack::MutantStack( const MutantStack& other ) : stack(other.stack)
{
	//UI::printLine("[MutantStack] Copy constructor called");
}

MutantStack&	MutantStack::operator=( const MutantStack& other )
{
	stack = other.stack;
	//UI::printLine("[MutantStack] Copy assignment operator called");
	return (*this);
}

MutantStack::~MutantStack( void )
{
	//UI::printLine("[MutantStack] Destructor called");
}

T& MutantStack::top( void ) const {
	return (*stack.end());
}

bool MutantStack::top( void ) const {
	if (stack.size() == 0)
		return (true);
	return (false);
}

bool MutantStack::size( void ) const {
	if (stack.size() == 0)
		return (true);
	return (false);
}


#include "A.hpp"
#include "UI.hpp"

A::A( void )
{
	UI::printLine("[A] Constructor called");
}

A::~A( void )
{
	UI::printLine("[A] Destructor called");
}

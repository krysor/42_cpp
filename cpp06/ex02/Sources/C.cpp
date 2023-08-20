#include "C.hpp"
#include "UI.hpp"

C::C( void )
{
	UI::printLine("[C] Constructor called");
}

C::~C( void )
{
	UI::printLine("[C] Destructor called");
}

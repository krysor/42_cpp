#include "functions.hpp"


Base*	generate( void )
{
	unsigned int	i;
	
	i = rand() % 3;
	switch (i) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (nullptr);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		UI::printLine("it's an A");
	else if (dynamic_cast<B*>(p) != NULL)
		UI::printLine("it's a B");
	else if (dynamic_cast<C*>(p) != NULL)
		UI::printLine("it's a C");
	else
		UI::printLine("it's neither A,B nor C");
}

void	identify(Base& p)
{	
	try {
		(void)dynamic_cast<A&>(p);
	}
	catch (std::exception & e) {
		try {
			(void)dynamic_cast<B&>(p);
		}
		catch (std::exception & e) {
			try {
				(void)dynamic_cast<C&>(p);
			}
			catch (std::exception & e) {
				UI::printLine("it's neither A,B nor C");
				return ;
			}
			UI::printLine("it's a C");
			return ;
		}
		UI::printLine("it's a B");
		return ;
	}
	UI::printLine("it's an A");
}

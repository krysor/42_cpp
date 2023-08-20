#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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
	
}

void	identify(Base& p)
{
	(void)p;
}

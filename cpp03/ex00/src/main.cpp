#include "ClapTrap.hpp"

int main( void ) 
{
	ClapTrap a;
	ClapTrap b("FLY");
	ClapTrap c = b;

	void (ClapTrap::*actions[])(void) const	= {&ClapTrap::attack, &ClapTrap::beRepaired}
	
	while (a.getHitPoints() && b.getHitPoints())
	{
		unsigned int	index;
		
		index = rand() % 2;
		if (index == 0)
		{

		}
		else
		{
			
		}
	}

	ClapTrap::attack(a, b);
	a.beRepaired(1);
	
	return (EXIT_SUCCESS);
}
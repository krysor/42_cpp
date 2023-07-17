#include "ClapTrap.hpp"
#include <time.h>

#include "UI.hpp"

void	simulateFight(const ClapTrap& a, const ClapTrap& b)
{
	ClapTrap 		clapTraps[] = {a, b};
	unsigned int	i 			= 0;
	while (clapTraps[0].getHitPoints() && clapTraps[0].getEnergyPoints()
		&& clapTraps[1].getHitPoints() && clapTraps[1].getEnergyPoints())
	{
		unsigned index = rand() % 2;
		if (index == 0)
			ClapTrap::attack(clapTraps[i % 2], clapTraps[(i + 1) % 2]);
		else
			clapTraps[i % 2].beRepaired(1);
		i++;
	}
	if (clapTraps[0].getHitPoints() && clapTraps[1].getHitPoints())
		UI::printLine("It's a TIE!");
	else if (clapTraps[0].getHitPoints() == 0)
		UI::printLine("ClapTrap " + clapTraps[1].getName() + " has won");
	else
		UI::printLine("ClapTrap " + clapTraps[0].getName() + " has won");
}

int main( void ) 
{
	ClapTrap a;
	ClapTrap b("FLY");
	ClapTrap c = b;

	srand(time(NULL));

	//simulate default fight
	simulateFight(a, b);

	//simulate fight with attack damage set to 1
	a.setAttackDamage(1);
	b.setAttackDamage(1);
	simulateFight(a, b);

	//simulate fight with attack damage set to 3
	a.setAttackDamage(3);
	b.setAttackDamage(3);
	simulateFight(a, b);
	
	return (EXIT_SUCCESS);
}
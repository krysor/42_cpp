#include "ScavTrap.hpp"
#include <time.h>
#include "UI.hpp"

void	simulateFight(const ScavTrap& a, const ScavTrap& b)
{
	ScavTrap 		scavTraps[] = {a, b};
	unsigned int	i;
	unsigned int	random;
	std::string		line;
	
	i = 0;
	while (scavTraps[0].getHitPoints() && scavTraps[0].getEnergyPoints()
		&& scavTraps[1].getHitPoints() && scavTraps[1].getEnergyPoints())
	{
		random = rand() % 2;
		if (random == 0)
			ScavTrap::attack(scavTraps[i % 2], scavTraps[(i + 1) % 2]);
		else
			scavTraps[i % 2].beRepaired(1);
		i++;
	}
	line = YELLOW;
	if (scavTraps[0].getHitPoints() && scavTraps[1].getHitPoints())
		line += "It's a TIE!";
	else if (scavTraps[0].getHitPoints() == 0)
		line += scavTraps[1].getName() + " has won";
	else
		line += scavTraps[0].getName() + " has won";
	line += RESET;
	UI::printLine(line);
}

int main( void ) 
{
	ScavTrap a;
	ScavTrap b("FLY");

	// srand(time(NULL));

	// //simulate default fight
	// simulateFight(a, b);

	// //simulate fight with attack damage set to 1
	// a.setAttackDamage(1);
	// b.setAttackDamage(1);
	// simulateFight(a, b);

	// //simulate fight with attack damage set to 3
	// a.setAttackDamage(3);
	// b.setAttackDamage(3);
	// simulateFight(a, b);
	
	return (EXIT_SUCCESS);
}
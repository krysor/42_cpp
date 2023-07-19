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
			ClapTrap::attackAndTakeDamage(scavTraps[i % 2], scavTraps[(i + 1) % 2]);
		else
			scavTraps[i % 2].beRepaired(10);
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
	UI::printLine(RED + "\nTEST: constructors + destructor\n" + RESET);
	{
		ScavTrap a;
		ScavTrap b("FLY");
		ScavTrap c(a);
		ScavTrap d = b;
	}

	UI::printLine(RED + "\nTEST: guardGate()\n" + RESET);
	{
		ScavTrap a("Bonjour");
		a.guardGate();
		a.guardGate();
	}

	UI::printLine(RED + "\nTEST: fight\n" + RESET);
	{
		ScavTrap a("MOI");
		ScavTrap b("TOI");
		
		srand(time(NULL));

		simulateFight(a, b);
	}

	return (EXIT_SUCCESS);
}
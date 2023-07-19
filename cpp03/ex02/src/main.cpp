#include "FragTrap.hpp"
#include <time.h>
#include "UI.hpp"

void	simulateFight(const FragTrap& a, const FragTrap& b)
{
	FragTrap 		fragTraps[] = {a, b};
	unsigned int	i;
	unsigned int	random;
	std::string		line;
	
	i = 0;
	while (fragTraps[0].getHitPoints() && fragTraps[0].getEnergyPoints()
		&& fragTraps[1].getHitPoints() && fragTraps[1].getEnergyPoints())
	{
		random = rand() % 2;
		if (random == 0)
			FragTrap::attack(fragTraps[i % 2], fragTraps[(i + 1) % 2]);
		else
			fragTraps[i % 2].beRepaired(10);
		i++;
	}
	line = YELLOW;
	if (fragTraps[0].getHitPoints() && fragTraps[1].getHitPoints())
		line += "It's a TIE!";
	else if (fragTraps[0].getHitPoints() == 0)
		line += fragTraps[1].getName() + " has won";
	else
		line += fragTraps[0].getName() + " has won";
	line += RESET;
	UI::printLine(line);
}

int main( void ) 
{
	UI::printLine(RED + "\nTEST: constructors + destructor\n" + RESET);
	{
		FragTrap a;
		FragTrap b("FLY");
		FragTrap c(a);
		FragTrap d = b;
	}

	UI::printLine(RED + "\nTEST: highFivesGuys()\n" + RESET);
	{
		FragTrap a("Bonjour");
		a.highFivesGuys();
	}

	UI::printLine(RED + "\nTEST: fight\n" + RESET);
	{
		FragTrap a("MOI");
		FragTrap b("TOI");
		
		srand(time(NULL));

		simulateFight(a, b);
	}

	return (EXIT_SUCCESS);
}
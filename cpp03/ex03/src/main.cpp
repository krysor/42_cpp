#include "DiamondTrap.hpp"
#include <time.h>
#include "UI.hpp"

// void	simulateFight(const DiamondTrap& a, const DiamondTrap& b)
// {
// 	DiamondTrap 	diamondTraps[] = {a, b};
// 	unsigned int	i;
// 	unsigned int	random;
// 	std::string		line;
	
// 	i = 0;
// 	while (diamondTraps[0].getHitPoints() && diamondTraps[0].getEnergyPoints()
// 		&& diamondTraps[1].getHitPoints() && diamondTraps[1].getEnergyPoints())
// 	{
// 		random = rand() % 2;
// 		if (random == 0)
// 			ClapTrap::attackAndTakeDamage(diamondTraps[i % 2], diamondTraps[(i + 1) % 2]);
// 		else
// 			diamondTraps[i % 2].beRepaired(10);
// 		i++;
// 	}
// 	line = YELLOW;
// 	if (diamondTraps[0].getHitPoints() && diamondTraps[1].getHitPoints())
// 		line += "It's a TIE!";
// 	else if (diamondTraps[0].getHitPoints() == 0)
// 		line += diamondTraps[1].getName() + " has won";
// 	else
// 		line += diamondTraps[0].getName() + " has won";
// 	line += RESET;
// 	UI::printLine(line);
// }

int main( void ) 
{
	UI::printLine(RED + "\nTEST: constructors + destructor\n" + RESET);
	{
		DiamondTrap a;
		UI::printLine("HP    : " + std::to_string(a.getHitPoints()));
		UI::printLine("Energy: " + std::to_string(a.getEnergyPoints()));
		UI::printLine("Damage: " + std::to_string(a.getAttackDamage()));
		UI::printLine("\n");
		// DiamondTrap b("FLY");
		// UI::printLine("\n");
		// DiamondTrap c(a);
		// UI::printLine("\n");
		// DiamondTrap d = b;
		// UI::printLine("\n");
	}

	// UI::printLine(RED + "\nTEST: special functions\n" + RESET);
	// {
	// 	DiamondTrap a("Bonjour");
		
	// 	a.guardGate();
	// 	a.highFivesGuys();
	// 	a.whoAmI();
	// }

	// UI::printLine(RED + "\nTEST: fight\n" + RESET);
	// {
	// 	DiamondTrap a("MOI");
	// 	DiamondTrap b("TOI");
		
	// 	srand(time(NULL));

	// 	simulateFight(a, b);
	// }

	return (EXIT_SUCCESS);
}
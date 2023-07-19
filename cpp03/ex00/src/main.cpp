#include "ClapTrap.hpp"
#include <time.h>

#include "UI.hpp"

void	simulateFight(const ClapTrap& a, const ClapTrap& b)
{
	ClapTrap 		clapTraps[] = {a, b};
	unsigned int	i;
	unsigned int	random;
	std::string		line;
	
	i = 0;
	while (clapTraps[0].getHitPoints() && clapTraps[0].getEnergyPoints()
		&& clapTraps[1].getHitPoints() && clapTraps[1].getEnergyPoints())
	{
		random = rand() % 2;
		if (random == 0)
			ClapTrap::attackAndTakeDamage(clapTraps[i % 2], clapTraps[(i + 1) % 2]);
		else
			clapTraps[i % 2].beRepaired(1);
		i++;
	}
	line = YELLOW;
	if (clapTraps[0].getHitPoints() && clapTraps[1].getHitPoints())
		line += "It's a TIE!";
	else if (clapTraps[0].getHitPoints() == 0)
		line += clapTraps[1].getName() + " has won";
	else
		line += clapTraps[0].getName() + " has won";
	line += RESET;
	UI::printLine(line);
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
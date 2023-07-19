#include "ScavTrap.hpp"
#include "UI.hpp"

ScavTrap::ScavTrap( void )
{
	UI::printLine(BLUE
		+ "ScavTrap Default constructor called"
			+ RESET);
	setName("NAMELESS ScavTrap");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap( std::string name )
{
	UI::printLine(BLUE
		+ "ScavTrap Name constructor called"
			+ RESET);
	setName(name);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap( const ScavTrap& scavTrap )
{
	UI::printLine(BLUE
		+ "ScavTrap Copy constructor called"
			+ RESET);
	operator=(scavTrap);
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& scavTrap )
{
	std::string		name;
	unsigned int	hitPoints, energyPoints, attackDamage;

	UI::printLine(BLUE
		+ "ScavTrap Copy assignment operator called"
			+ RESET);
	name			=	scavTrap.getName();
	hitPoints		=	scavTrap.getHitPoints();
	energyPoints	=	scavTrap.getEnergyPoints();
	attackDamage	=	scavTrap.getAttackDamage();
	setName(name);
	setHitPoints(hitPoints);
	setEnergyPoints(energyPoints);
	setAttackDamage(attackDamage);
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	UI::printLine(BLUE
		+ "ScavTrap Destructor called"
			+ RESET);
}

void	ScavTrap::attack( const std::string& target )
{
	unsigned int	energyPoints;
	std::string		line;

	energyPoints = getEnergyPoints();
	line = BLUE + "ScavTrap " + GREEN + getName();
	if (getHitPoints() == 0)
		line += " is dead and can't do anything";
	else if (energyPoints == 0)
		line += " can't attack because it has no energy points left";
	else
	{
		energyPoints--;
		setEnergyPoints(energyPoints);
		line += " attacked " + target + " causing "
			  + std::to_string(getAttackDamage()) + " points of damage";
	}
	UI::printLine(line + RESET);
}

void	ScavTrap::guardGate( void ) const
{
	static unsigned int	i = 0;
	std::string			line;

	if (i == 0)
	{
		i = 1;
		line = BLUE + "ScavTrap " + getName()
					+ " is now in Gate keeper mode"
					+ RESET;
	}
	else if (i == 1)
	{
		i = 0;
		line = BLUE + "ScavTrap " + getName()
			+ " left Gate keeper mode"
			+ RESET;
	}
	UI::printLine(line);
}

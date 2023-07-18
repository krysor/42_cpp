#include "ScavTrap.hpp"
#include "UI.hpp"

ScavTrap::ScavTrap( void )
{
	UI::printLine("ScavTrap Default constructor called");
	setName("NAMELESS ScavTrap");
}

ScavTrap::ScavTrap( std::string name )
{
	UI::printLine("ScavTrap Name constructor called");
	setName(name);
}

ScavTrap::ScavTrap( const ScavTrap& scavTrap )
{
	UI::printLine("ScavTrap Copy constructor called");
	operator=(scavTrap);
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& scavTrap )
{
	UI::printLine("ScavTrap Copy assignment operator called");
	// std::string		name;
	// unsigned int	hitPoints, energyPoints, attackDamage;

	// name = scavTrap.getName();
	// hitPoints = scavTrap.getHitPoints();
	// energyPoints = scavTrap.getEnergyPoints();
	// attackDamage = scavTrap.getAttackDamage();
	// setName(name);
	// setHitPoints(hitPoints);
	// setEnergyPoints(energyPoints);
	// setAttackDamage(attackDamage);
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	UI::printLine("ScavTrap Destructor called");
}

void	ScavTrap::attack( const std::string& target )
{
	unsigned int	energyPoints;
	std::string		line;

	energyPoints = getEnergyPoints();
	line = GREEN + "ScavTrap " + getName();
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

void	ScavTrap::attack( ScavTrap& attacker, ScavTrap& victim )
{
	std::string		nameVictim;
	unsigned int	energyPointsAttacker;
	unsigned int	damage;
	
	nameVictim = victim.getName();
	energyPointsAttacker = attacker.getEnergyPoints();
	attacker.attack(nameVictim);
	if (energyPointsAttacker != 0)
	{
		damage = attacker.getAttackDamage();
		victim.takeDamage(damage);
	}
}
#include "FragTrap.hpp"
#include "UI.hpp"

FragTrap::FragTrap( void )
{
	UI::printLine(GREEN
		+ "FragTrap Default constructor called"
			+ RESET);
	setName("NAMELESS FragTrap");
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap( std::string name )
{
	UI::printLine(GREEN
		+ "FragTrap Name constructor called"
			+ RESET);
	setName(name);
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap( const FragTrap& fragTrap )
{
	UI::printLine(GREEN
		+ "FragTrap Copy constructor called"
			+ RESET);
	operator=(fragTrap);
}

FragTrap&	FragTrap::operator=( const FragTrap& fragTrap )
{
	std::string		name;
	unsigned int	hitPoints, energyPoints, attackDamage;

	UI::printLine(GREEN
		+ "FragTrap Copy assignment operator called"
			+ RESET);
	name			=	fragTrap.getName();
	hitPoints		=	fragTrap.getHitPoints();
	energyPoints	=	fragTrap.getEnergyPoints();
	attackDamage	=	fragTrap.getAttackDamage();
	setName(name);
	setHitPoints(hitPoints);
	setEnergyPoints(energyPoints);
	setAttackDamage(attackDamage);
	return (*this);
}

FragTrap::~FragTrap( void )
{
	UI::printLine(GREEN
		+ "FragTrap Destructor called"
			+ RESET);
}

void	FragTrap::highFivesGuys( void )
{
	UI::printLine(getName()
				+ ": ha fives guys!");
}

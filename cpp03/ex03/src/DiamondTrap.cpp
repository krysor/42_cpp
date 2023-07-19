#include "DiamondTrap.hpp"
#include "UI.hpp"

DiamondTrap::DiamondTrap( void )
{
	UI::printLine(YELLOW
		+ "DiamondTrap Default constructor called"
			+ RESET);
	setName("NAMELESS DiamondTrap");
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap( std::string name )
{
	UI::printLine(YELLOW
		+ "DiamondTrap Name constructor called"
			+ RESET);
	this->name = name;
	setName(name + "_clap_name");
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap( const DiamondTrap& DiamondTrap )
{
	UI::printLine(YELLOW
		+ "DiamondTrap Copy constructor called"
			+ RESET);
	operator=(DiamondTrap);
}

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& DiamondTrap )
{
	std::string		name;
	unsigned int	hitPoints, energyPoints, attackDamage;

	UI::printLine(YELLOW
		+ "DiamondTrap Copy assignment operator called"
			+ RESET);
	name			=	DiamondTrap.getName();
	hitPoints		=	DiamondTrap.getHitPoints();
	energyPoints	=	DiamondTrap.getEnergyPoints();
	attackDamage	=	DiamondTrap.getAttackDamage();
	setName(name);
	setHitPoints(hitPoints);
	setEnergyPoints(energyPoints);
	setAttackDamage(attackDamage);
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	UI::printLine(YELLOW
		+ "DiamondTrap Destructor called"
			+ RESET);
}

void	DiamondTrap::whoAmI( void )
{
	std::string	line;

	line = "My Diamond  name is: " + this->name;
	UI::printLine(line);
	line = "My ClapTrap name is: " + getName();
	UI::printLine(line);
}
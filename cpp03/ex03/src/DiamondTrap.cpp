#include "DiamondTrap.hpp"
#include "UI.hpp"

DiamondTrap::DiamondTrap( void )
{
	UI::printLine(YELLOW
		+ "DiamondTrap Default constructor called"
			+ RESET);
	setName("NAMELESS DiamondTrap");
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap( std::string name )
{
	UI::printLine(YELLOW
		+ "DiamondTrap Name constructor called"
			+ RESET);
	this->name = name;
	setName(name + "_clap_name");
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
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
	std::string		nameTmp;
	unsigned int	hitPointsTmp, energyPointsTmp, attackDamageTmp;

	UI::printLine(YELLOW
		+ "DiamondTrap Copy assignment operator called"
			+ RESET);
	nameTmp			=	DiamondTrap.getName();
	hitPointsTmp	=	DiamondTrap.getHitPoints();
	energyPointsTmp	=	DiamondTrap.getEnergyPoints();
	attackDamageTmp	=	DiamondTrap.getAttackDamage();
	setName(nameTmp);
	setHitPoints(hitPointsTmp);
	setEnergyPoints(energyPointsTmp);
	setAttackDamage(attackDamageTmp);
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
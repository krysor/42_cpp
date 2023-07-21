#include "DiamondTrap.hpp"
#include "UI.hpp"

DiamondTrap::DiamondTrap( void )
{
	UI::printLine(YELLOW
		+ "DiamondTrap Default constructor called"
			+ RESET);
	this->_name = "NAMELESS DiamondTrap";
	setName("NAMELESS DiamondTrap" + std::string("_clap_name"));
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap( std::string name )
{
	UI::printLine(YELLOW
		+ "DiamondTrap Name constructor called"
			+ RESET);
	this->_name = name;
	setName(name + "_clap_name");
	setHitPoints(100);
	setEnergyPoints(50);
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
	std::string		nameClapTmp;
	unsigned int	hitPointsTmp, energyPointsTmp, attackDamageTmp;

	UI::printLine(YELLOW
		+ "DiamondTrap Copy assignment operator called"
			+ RESET);
	nameClapTmp		=	DiamondTrap.getName();
	hitPointsTmp	=	DiamondTrap.getHitPoints();
	energyPointsTmp	=	DiamondTrap.getEnergyPoints();
	attackDamageTmp	=	DiamondTrap.getAttackDamage();
	this->_name = nameClapTmp.substr(0, nameClapTmp.length()
					- std::string("_clap_name").length());
	setName(nameClapTmp);
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

	line = "My Diamond  name is: " + this->_name;
	UI::printLine(line);
	line = "My ClapTrap name is: " + getName();
	UI::printLine(line);
}

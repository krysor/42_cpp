#include "ClapTrap.hpp"
#include "UI.hpp"

ClapTrap::ClapTrap( void )
{
	UI::printLine("Default constructor called");
	setName("NAMELESS");
	setHitPoints(10);
	setEnergyPoints(10);
	setAttackDamage(0);
}

ClapTrap::ClapTrap( std::string name )
{
	UI::printLine("Name constructor called");
	setName(name);
	setHitPoints(10);
	setEnergyPoints(10);
	setAttackDamage(0);
}

ClapTrap::ClapTrap( const ClapTrap& clapTrap )
{
	UI::printLine("Copy constructor called");
	operator=(clapTrap);
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& clapTrap )
{
	UI::printLine("Copy assignment operator called");
	std::string		name;
	unsigned int	hitPoints, energyPoints, attackDamage;

	name = clapTrap.getName();
	hitPoints = clapTrap.getHitPoints();
	energyPoints = clapTrap.getEnergyPoints();
	attackDamage = clapTrap.getAttackDamage();
	setName(name);
	setHitPoints(hitPoints);
	setEnergyPoints(energyPoints);
	setAttackDamage(attackDamage);
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	UI::printLine("Destructor called");
}

void	ClapTrap::attack( const std::string& target )
{
	unsigned int	energyPoints;
	std::string		line;

	energyPoints = getEnergyPoints();
	line = getName();
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
	UI::printLine(line);
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	unsigned int	hitPoints;
	std::string		line;

	hitPoints = getHitPoints();
	line = getName();
	if (hitPoints == 0)
		line += " is already dead and can't take any more damage";
	else if ((int)hitPoints - (int)amount <= 0)
	{
		setHitPoints(0);
		line += " has taken " + std::to_string(amount) + " damage and is now dead";
	}
	else
	{
		setHitPoints(hitPoints - amount);
		line += " has taken " + std::to_string(amount) + " damage";
		line += ". " + std::to_string(getHitPoints()) + " HP remaining";
	}
	UI::printLine(line);
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	unsigned int	hitPoints;
	unsigned int	energyPoints;
	std::string		line;

	hitPoints = getHitPoints();
	energyPoints = getEnergyPoints();
	line = getName();
	if (hitPoints == 0)
		line += " is already dead and can't repair itself";
	else if (energyPoints == 0)
		line += " can't repair itself because it has no energy points left";
	else
	{
		energyPoints--;
		setEnergyPoints(energyPoints);
		hitPoints += amount;
		setHitPoints(hitPoints);
		line += " repaired itself restoring " + std::to_string(amount) + " hitpoint(s)";
		line += ". " + std::to_string(getHitPoints()) + " HP remaining";
	}
	UI::printLine(line);
}

const std::string&		ClapTrap::getName( void ) const
{
	return (this->_name);
}

const unsigned int&		ClapTrap::getHitPoints( void ) const
{
	return (this->_hitPoints);
}

const unsigned int&		ClapTrap::getEnergyPoints( void ) const
{
	return (this->_energyPoints);
}

const unsigned int&		ClapTrap::getAttackDamage( void ) const
{
	return (this->_attackDamage);
}

void	ClapTrap::setName( const std::string name )
{
	this->_name = name;
}

void	ClapTrap::setHitPoints( unsigned int hitPoints )
{
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints( unsigned int energyPoints )
{
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage( unsigned int attackDamage )
{
	this->_attackDamage = attackDamage;
}

void	ClapTrap::attack( ClapTrap& attacker, ClapTrap& victim )
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
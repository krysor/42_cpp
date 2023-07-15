#include "ClapTrap.hpp"
#include "UI.hpp"

ClapTrap::ClapTrap( void )
{
	UI::printLine("Default constructor called");
	setName("");
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
	
}

void	ClapTrap::takeDamage( unsigned int amount )
{

}

void	ClapTrap::beRepaired( unsigned int amount )
{

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
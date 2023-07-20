#pragma once
#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap {


private:

	std::string	_name;


public:

	DiamondTrap( void );
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap& diamondTrap );
	DiamondTrap&	operator=( const DiamondTrap& diamondTrap );
	~DiamondTrap( void );

	// using FragTrap::getHitPoints;
	// using ScavTrap::getEnergyPoints;
	// using FragTrap::getAttackDamage;

	// using FragTrap::setHitPoints;
	// using ScavTrap::setEnergyPoints;
	// using FragTrap::setAttackDamage;

	void	whoAmI( void );
};

#endif
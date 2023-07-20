#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"

class ScavTrap : virtual public  ClapTrap {


public:

	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap& scavTrap );
	ScavTrap&	operator=( const ScavTrap& scavTrap );
	~ScavTrap( void );

	void	attack( const std::string& target );
	void	guardGate( void ) const;
};

#endif
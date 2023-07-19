#pragma once
#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include "ClapTrap.hpp"

class FragTrap : public virtual  ClapTrap {


public:

	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( const FragTrap& fragTrap );
	FragTrap&	operator=( const FragTrap& fragTrap );
	~FragTrap( void );

	void	highFivesGuys( void );
};

#endif
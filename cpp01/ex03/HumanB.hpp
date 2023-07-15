#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.hpp"

class HumanB {


private:

	Weapon*		_weapon;
	std::string _name;

public:

	HumanB( std::string name);
	~HumanB( void );

	void	attack( void ) const;
	void	setWeapon( Weapon& weapon );

};

#endif
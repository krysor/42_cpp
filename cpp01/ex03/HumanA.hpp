#pragma once
#ifndef __HUMANA_H__
#define __HUMANA_H__

#include "Weapon.hpp"

class HumanA {


private:

	Weapon*		_weapon;
	std::string _name;

public:

	HumanA( std::string name, Weapon& weapon );
	~HumanA( void );

	void	attack( void ) const;
	void	setWeapon( Weapon& weapon );

};

#endif
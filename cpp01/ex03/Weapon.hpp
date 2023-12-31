#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>

class Weapon {


private:

	std::string _type;


public:

	Weapon( void );
	Weapon( std::string type );
	~Weapon( void );

	const std::string&	getType( void ) const;
	void				setType( std::string type );

};

#endif
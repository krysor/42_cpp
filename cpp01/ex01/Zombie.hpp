#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>
#include <iostream>

class Zombie {


private:

	std::string _name;


public:

	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );

	void	setName( std::string name );
	void	announce( void ) const;


};

Zombie*	zombieHorde( int N, std::string name );

#endif
#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>
#include <iostream>

class Zombie {


private:

	std::string _name;


public:

	Zombie(std::string name);
	~Zombie( void );

	void	announce( void ) const;


};

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );

#endif
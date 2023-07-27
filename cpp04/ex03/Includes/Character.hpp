#pragma once
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>

#define INVENTORYSIZE 4

class Character : public ICharacter {


protected:

	std::string	_name;
	AMateria*	_inventory[INVENTORYSIZE];

public:

	Character( void );
	Character( const Character& name );
	Character&	operator=( const Character& other );
	~Character( void );

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx) = 0;
	void use(int idx, ICharacter& target);
};

#endif
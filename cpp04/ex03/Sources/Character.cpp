#include "Character.hpp"
#include "UI.hpp"

Character::Character( void )
{
	UI::printLine("[Character] Default constructor called");
	for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character( std::string const & name )
{
	UI::printLine("[Character] Name constructor called");
	this->_name = name;
	for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character( const Character& other )
{
	UI::printLine("[Character] Copy constructor called");
	this->_name = other._name;
	for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
		this->_inventory[i] = new other._inventory[i];
	}
}

Character&	Character::operator=( const Character& other )
{
	UI::printLine("[Character] Copy assignment operator called");
	for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
		delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	this->_name = other._name;
	for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
		this->_inventory[i] = new other._inventory[i];
	}
	return (*this);
}

Character::~Character( void )
{
	UI::printLine("[Character] Destructor called");
	for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
		delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
}

std::string const & Character::getName() const
{
	return (this->_name);
}

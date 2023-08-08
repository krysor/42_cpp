#include "Character.hpp"
#include "UI.hpp"

Character::Character( void ) : _inventory()
{
	UI::printLine("[Character] Default constructor called");
	// for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
	// 	this->_inventory[i] = NULL;
	// }
}

Character::Character( std::string const & name ) : _inventory()
{	
	UI::printLine("[Character] Name constructor called");
	this->_name = name;
	// for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
	// 	this->_inventory[i] = NULL;
	// }
}

Character::Character( const Character& other )
{
	UI::printLine("[Character] Copy constructor called");
	operator=(other);
}

Character&	Character::operator=( const Character& other )
{
	UI::printLine("[Character] Copy assignment operator called");
	// for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
	// 	delete this->_inventory[i];
	// 	this->_inventory[i] = NULL;
	// }
	this->_name = other._name;
	for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
		this->_inventory[i] = other._inventory[i];
	}
	// this->_name = other._name;
	// for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
	// 	this->_inventory[i] = new other._inventory[i];
	// }
	return (*this);
}

Character::~Character( void )
{
	UI::printLine("[Character] Destructor called");
	// for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
	// 	if (this->_inventory[i] != NULL)
	// 		delete this->_inventory[i];
	// 	this->_inventory[i] = NULL;
	// }
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	unsigned int i;

	for (i = 0 ; i < INVENTORYSIZE ; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			break ;
		}
	}
	if (i == 4) {
		UI::printLine("The inventory is full.");
	}
}

void Character::unequip(int idx)
{
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	this->_inventory[idx]->use(target);
}

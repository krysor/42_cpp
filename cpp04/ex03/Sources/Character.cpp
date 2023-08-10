#include "Character.hpp"
#include "UI.hpp"

Character::Character( void ) : _inventory()
{
	UI::printLine("[Character] Default constructor called");
}

Character::Character( std::string const & name ) : _inventory()
{	
	UI::printLine("[Character] Name constructor called");
	this->_name = name;
}

Character::Character( const Character& other ) : _inventory()
{
	UI::printLine("[Character] Copy constructor called");
	this->_name = other._name;
	for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
		if (other._inventory[i] != nullptr)
			this->_inventory[i] = other._inventory[i]->clone();
	}
}

Character&	Character::operator=( const Character& other )
{
	UI::printLine("[Character] Copy assignment operator called");
	this->_name = other._name;
	for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
		delete this->_inventory[i];
		this->_inventory[i] = nullptr;
	}
	for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
		if (other._inventory[i] != nullptr)
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

Character::~Character( void )
{
	UI::printLine("[Character] Destructor called");
	for (unsigned int i = 0; i < INVENTORYSIZE; i++) {
		if (this->_inventory[i] != nullptr) {
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
		}
	}
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	unsigned int i;

	if (m == nullptr)
		return ;
	for (i = 0 ; i < INVENTORYSIZE ; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			break ;
		}
	}
	if (i == 4) {
		UI::printLine("The " + this->_name + "'s inventory is full.");
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORYSIZE) {
		UI::printLine("The given inventory index " + std::to_string(idx) + " is incorrect.");
		return ;
	}
	this->_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORYSIZE) {
		UI::printLine("The given inventory index " + std::to_string(idx) + " is incorrect.");
		return ;
	}
	if (this->_inventory[idx] == nullptr) {
		UI::printLine(this->_name + "has no Materia at index " + std::to_string(idx));
		return ;
	}
	this->_inventory[idx]->use(target);
}

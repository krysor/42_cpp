#include "MateriaSource.hpp"
#include "UI.hpp"

MateriaSource::MateriaSource( void ) : Character() {
	UI::printLine("[MateriaSource] Default constructor called");
}

MateriaSource::MateriaSource( const MateriaSource& other ) : Character(other) {
	UI::printLine("[MateriaSource] Copy constructor called");
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other ) {
	UI::printLine("[MateriaSource] Copy assignment operator called");
	for (int i = 0 ; i < INVENTORYSIZE ; i++) {
		if (_inventory[i] != nullptr) {
			delete _inventory[i];
		}
	}
	for (int i = 0 ; i < INVENTORYSIZE ; i++) {
		if (other._inventory[i] != nullptr) {
			_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource( void ) {
	UI::printLine("[MateriaSource] Destructor called");
}

void 		MateriaSource::learnMateria(AMateria* m) {
	if (m != nullptr && _inventory[INVENTORYSIZE - 1] == nullptr)
		equip(m->clone());
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0 ; i < INVENTORYSIZE ; i++) {
		if (_inventory[i] != nullptr && _inventory[i]->getType() == type) {
			return (_inventory[i]->clone());
		}
	}
	return (nullptr);
}

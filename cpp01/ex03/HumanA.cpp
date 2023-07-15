#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
	std::cout << "Creating a HumanA called " << name << " with a " << weapon.getType() << "..." << std::endl;
	this->_name = name;
	this->_weapon = &weapon;
}

HumanA::~HumanA(void)
{
	std::cout << "Destructing a HumanA called " << this->_name << "..." << std::endl;
}

void	HumanA::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
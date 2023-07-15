#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	std::cout << "Creating HumanB called " << name << std::endl;
	this->_name = name;
	//this->_weapon->setType("");
}

HumanB::~HumanB(void)
{
	std::cout << "Destructing HumanB called " << this->_name << "..." << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	if (this->_weapon->getType().empty() == false)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack with :-(" << std::endl;
}
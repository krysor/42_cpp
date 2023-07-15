#include "Weapon.hpp"

Weapon::Weapon( void )
{
}

Weapon::Weapon( std::string type )
{
	setType(type);
	std::cout << "Creating a weapon of type " << this->getType() << "..." << std::endl;
}

Weapon::~Weapon( void )
{
	std::cout << "Destructing a weapon of type " << this->getType() << "..." << std::endl;
}

const std::string& Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
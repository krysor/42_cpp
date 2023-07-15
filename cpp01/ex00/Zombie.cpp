#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Constructing Zombie named " + this->_name + "..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructing Zombie named " + this->_name + "..." << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}
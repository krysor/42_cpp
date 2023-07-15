#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie0 = Zombie("zero");
	zombie0.announce();

	Zombie* zombie1_pnt = newZombie("one");
	zombie1_pnt->announce();

	randomChump("two");

	delete zombie1_pnt;
}
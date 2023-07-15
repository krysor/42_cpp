#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

// int	main(void)
// {
// 	Weapon weapon1 = Weapon("handgun");

// 	HumanA	humanA("Tony", weapon1);
// 	HumanB	humanB("pedestrian");

// 	humanA.attack();
// 	humanB.attack();
	
// 	Weapon weapon2 = Weapon("m32");
// 	humanB.setWeapon(weapon2);

// 	humanA.attack();
// 	humanB.attack();

// 	weapon1.setType("flamethrower");
// 	weapon2.setType("minigun");

// 	humanA.attack();
// 	humanB.attack();
// }
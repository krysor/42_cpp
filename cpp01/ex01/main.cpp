#include "Zombie.hpp"

int	main(void)
{
	int	N = 3;
	Zombie *horde = zombieHorde(N, "zoombaye");
	for (int i = 0; i < N; i++){
		horde[i].announce();
	}
	delete [] horde;
	system("leaks ex01");
}
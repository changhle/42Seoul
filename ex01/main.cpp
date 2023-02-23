#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main()
{
	Zombie	*zombie;

	zombie = zombieHorde(5, "changhle");
	for (int i = 0; i < 5; i++)
		zombie[i].announce();
	delete[] zombie;
}
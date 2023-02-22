#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	Zombie	*heap;
	heap = newZombie("heap");
	heap->announce();
	randomChump("stack");
	delete heap;
}
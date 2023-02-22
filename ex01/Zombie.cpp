#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << name << ": Born..." << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << ": Dead..." << std::endl;
}
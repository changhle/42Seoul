#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie is born..." << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << ": Dead..." << std::endl;
}
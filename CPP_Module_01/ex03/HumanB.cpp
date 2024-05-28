#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	weapon = NULL;
}

void	HumanB::attack()
{
	if (!weapon)
	{
		std::cout << "No weapon!" << std::endl;
		return;
	}
	std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &wp)
{
	weapon = &wp;
}
#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type) {
	setType(weapon_type);
}

void	Weapon::setType(std::string weapon_type)
{
	this->weapon_type = weapon_type;
}

const std::string	&Weapon::getType()
{
	return (weapon_type);
}

Weapon::~Weapon() {
}
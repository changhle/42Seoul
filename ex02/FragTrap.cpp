#include "FragTrap.hpp"

FragTrap::FragTrap() {
	name = "default";
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap " << name << " constructor" << std::endl;;
}

FragTrap::FragTrap(std::string name) {
	this->name = name;
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap " << name << " constructor" << std::endl;;
}

FragTrap::FragTrap(const FragTrap& obj) {
	name = obj.name;
	HitPoints = obj.HitPoints;
	EnergyPoints = obj.EnergyPoints;
	AttackDamage = obj.AttackDamage;
	std::cout << "FragTrap Copy constructor" << std::endl;;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " Destructor" << std::endl;;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
	name = obj.name;
	HitPoints = obj.HitPoints;
	EnergyPoints = obj.EnergyPoints;
	AttackDamage = obj.AttackDamage;
	std::cout << "FragTrap Copy assignment operator" << std::endl;;
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "ScavTrap " << name << " high fives!" << std::endl;
}
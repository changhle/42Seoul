#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	name = "default";
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor" << std::endl;;
}

ScavTrap::ScavTrap(std::string name) {
	this->name = name;
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor" << std::endl;;
}

ScavTrap::ScavTrap(const ScavTrap& obj) {
	name = obj.name;
	HitPoints = obj.HitPoints;
	EnergyPoints = obj.EnergyPoints;
	AttackDamage = obj.AttackDamage;
	std::cout << "ScavTrap Copy constructor" << std::endl;;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " Destructor" << std::endl;;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	name = obj.name;
	HitPoints = obj.HitPoints;
	EnergyPoints = obj.EnergyPoints;
	AttackDamage = obj.AttackDamage;
	std::cout << "ScavTrap Copy assignment operator" << std::endl;;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (!HitPoints || !EnergyPoints)
		std::cout << "ScavTrap " << name << " can't attack..." << std::endl;
	else
	{
		EnergyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
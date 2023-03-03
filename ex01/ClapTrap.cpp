#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	name = "default";
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
	std::cout << "ClapTrap " << name << " constructor" << std::endl;;
}

ClapTrap::ClapTrap(std::string name) {
	this->name = name;
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
	std::cout << "ClapTrap " << name << " constructor" << std::endl;;
}

ClapTrap::ClapTrap(const ClapTrap& obj) {
	std::cout << "ClapTrap Copy constructor" << std::endl;;
	*this = obj;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " Destructor" << std::endl;;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	name = obj.name;
	HitPoints = obj.HitPoints;
	EnergyPoints = obj.EnergyPoints;
	AttackDamage = obj.AttackDamage;
	std::cout << "ClapTrap Copy assignment operator" << std::endl;;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!HitPoints || !EnergyPoints)
		std::cout << "ClapTrap " << name << " can't attack..." << std::endl;
	else
	{
		EnergyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!HitPoints)
	{
		std::cout << "ClapTrap " << name << " already dead..." << std::endl;
		return;
	}
	if (HitPoints > amount)
		HitPoints -= amount;
	else
		HitPoints = 0;
	std::cout << "ClapTrap " << name << " taken " << amount << " damage" << std::endl;
	if (!HitPoints)
		std::cout << "ClapTrap " << name << " dead..." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!HitPoints || !EnergyPoints)
		std::cout << "ClapTrap " << name << " can't be repaired..." << std::endl;
	else
	{
		HitPoints += amount;
		EnergyPoints--;
		std::cout << "ClapTrap " << name << " be repaired " << amount << " Hitpoints!" << std::endl;
		std::cout << "ClapTrap " << name << " has " << HitPoints << " Hitpoints" << std::endl;
	}
}
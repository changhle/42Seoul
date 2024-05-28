#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("A");
	ScavTrap b("B");
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(20);
	b.beRepaired(5);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(20);
	a.beRepaired(5);
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(20);
	b.beRepaired(5);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(20);
	a.beRepaired(5);
	std::cout << std::endl;	

	a.guardGate();
	b.guardGate();
	std::cout << std::endl;	
	return (0);
}
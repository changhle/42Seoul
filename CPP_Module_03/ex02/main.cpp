#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a("A");
	FragTrap b("B");
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(30);
	b.beRepaired(5);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(30);
	a.beRepaired(5);
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(30);
	b.beRepaired(5);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(30);
	a.beRepaired(5);
	std::cout << std::endl;	

	a.highFivesGuys();
	b.highFivesGuys();
	std::cout << std::endl;	
	return (0);
}
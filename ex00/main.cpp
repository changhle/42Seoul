#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	std::cout << std::endl;

	b.attack("A");
	std::cout << std::endl;
	
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	std::cout << std::endl;

	a.beRepaired(1);
	std::cout << std::endl;

	return (0);
}
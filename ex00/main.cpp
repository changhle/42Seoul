#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	b.attack("A");
	
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	return (0);
}
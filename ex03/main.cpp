#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	// std::cout << "-------------------------" << std::endl;
	me->equip(tmp);
	// std::cout << "-------------------------" << std::endl;
	tmp = src->createMateria("cure");
	// std::cout << "-------------------------" << std::endl;
	me->equip(tmp);
	// std::cout << "-------------------------" << std::endl;
	ICharacter* bob = new Character("bob");
	// std::cout << "-------------------------" << std::endl;
	me->use(0, *bob);
	// std::cout << "-------------------------" << std::endl;
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
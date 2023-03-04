#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	std::cout << std::endl;

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;
	std::cout << std::endl;

	const WrongAnimal* wrong = new WrongCat();
	std::cout << std::endl;

	std::cout << wrong->getType() << " " << std::endl;
	std::cout << std::endl;

	wrong->makeSound();
	std::cout << std::endl;

	delete wrong;
	std::cout << std::endl;

	return 0;
}

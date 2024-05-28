#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// const Animal* meta = new Animal();
	const Animal* animal = new Cat();
	std::cout << std::endl;

	std::cout << animal->getType() << " " << std::endl;
	std::cout << std::endl;

	animal->makeSound();
	std::cout << std::endl;

	delete animal;
	std::cout << std::endl;

	return 0;
}

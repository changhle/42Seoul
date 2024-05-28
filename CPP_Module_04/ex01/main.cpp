#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal	*animal[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < (10 / 2))
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete animal[i];
	std::cout << std::endl;

	const Dog	*dog = new Dog();
	const Cat	*cat = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Dog's idea" << i << " : " << dog->getBrain()->getIdea(i) << std::endl;
		std::cout << "Cat's idea" << i << " : " << cat->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;

	delete dog;
	delete cat;
	std::cout << std::endl;

	return 0;
}

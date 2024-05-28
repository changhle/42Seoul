#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat Default constructor" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& obj) {
	std::cout << "Cat Copy constructor" << std::endl;
	type = obj.type;
	brain = new Brain();
	*brain = *obj.brain;
}

Cat::~Cat() {
	std::cout << "Cat Destructor" << std::endl;
	delete brain;
}

Cat& Cat::operator=(const Cat& obj) {
	std::cout << "Cat Copy assignment operator" << std::endl;
	type = obj.type;
	*brain = *obj.brain;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat shouts 'meow'" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (brain);
}
#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog Default constructor" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& obj) {
	std::cout << "Dog Copy constructor" << std::endl;
	type = obj.type;
	brain = new Brain();
	*brain = *obj.brain;
}

Dog::~Dog() {
	std::cout << "Dog Destructor" << std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog& obj) {
	std::cout << "Dog Copy assignment operator" << std::endl;
	type = obj.type;
	*brain = *obj.brain;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog shouts 'bow'" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (brain);
}
#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog Default constructor" << '\n';
}

Dog::Dog(const Dog& obj) {
	std::cout << "Dog Copy constructor" << '\n';
}

Dog::~Dog() {
	std::cout << "Dog Destructor" << '\n';
}

Dog& Dog::operator=(const Dog& obj) {
	std::cout << "Dog Copy assignment operator" << '\n';
	return (*this);
}

void	Dog::makeSound()
{
	std::cout << type << " shouts default" << std::endl;
}
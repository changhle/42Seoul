#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog Default constructor" << std::endl;
}

Dog::Dog(const Dog& obj) {
	std::cout << "Dog Copy constructor" << std::endl;
	*this = obj;
}

Dog::~Dog() {
	std::cout << "Dog Destructor" << std::endl;
}

Dog& Dog::operator=(const Dog& obj) {
	std::cout << "Dog Copy assignment operator" << std::endl;
	type = obj.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog shouts 'bow'" << std::endl;
}
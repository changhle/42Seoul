#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat Default constructor" << std::endl;
}

Cat::Cat(const Cat& obj) {
	std::cout << "Cat Copy constructor" << std::endl;
	*this = obj;
}

Cat::~Cat() {
	std::cout << "Cat Destructor" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) {
	std::cout << "Cat Copy assignment operator" << std::endl;
	type = obj.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat shouts 'meow'" << std::endl;
}
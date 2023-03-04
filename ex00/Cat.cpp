#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat Default constructor" << '\n';
}

Cat::Cat(const Cat& obj) {
	std::cout << "Cat Copy constructor" << '\n';
}

Cat::~Cat() {
	std::cout << "Cat Destructor" << '\n';
}

Cat& Cat::operator=(const Cat& obj) {
	std::cout << "Cat Copy assignment operator" << '\n';
	return (*this);
}

void	Cat::makeSound()
{
	std::cout << type << " shouts default" << std::endl;
}
#include "Animal.hpp"

Animal::Animal() {
	type = "default";
	std::cout << "Animal Default constructor" << std::endl;
}

Animal::Animal(const Animal& obj) {
	std::cout << "Animal Copy constructor" << std::endl;
	*this = obj;
}

Animal::~Animal() {
	std::cout << "Animal Destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& obj) {
	std::cout << "Animal Copy assignment operator" << std::endl;
	type = obj.type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal shouts default" << std::endl;
}
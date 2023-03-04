#include "Animal.hpp"

Animal::Animal() {
	type = "default";
	std::cout << "Animal " << type << " constructor" << std::endl;
}

Animal::Animal(const Animal& obj) {
	type = obj.type;
	std::cout << "Animal Copy constructor" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal " << type << " Destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& obj) {
	type = obj.type;
	std::cout << "Animal Copy assignment operator" << std::endl;
	return (*this);
}

std::string	Animal::getType() const
{
	return (type);
}

void	Animal::makeSound(void) const
{
	std::cout << type << " shouts default" << std::endl;
}
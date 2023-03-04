#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	type = "default";
	std::cout << "WrongAnimal Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
	std::cout << "WrongAnimal Copy constructor" << std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
	std::cout << "WrongAnimal Copy assignment operator" << std::endl;
	type = obj.type;
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal shouts default" << std::endl;
}
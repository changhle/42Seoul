#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat Default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) {
	std::cout << "WrongCat Copy constructor" << std::endl;
	*this = obj;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
	std::cout << "WrongCat Copy assignment operator" << std::endl;
	type = obj.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat shouts 'Worng meow'" << std::endl;
}
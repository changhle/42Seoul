#include "Ice.hpp"

Ice::Ice()
{
	this->type = "Ice";
}

Ice::Ice(const Ice& obj)
{
	*this = obj;
}

Ice& Ice::operator=(const Ice& obj)
{
	this->type = obj.getType();
	return (*this);
}

Ice::~Ice() {}

AMateria* Ice::clone() const
{
	return (new Ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
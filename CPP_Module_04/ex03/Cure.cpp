#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(const Cure& obj)
{
	*this = obj;
}

Cure& Cure::operator=(const Cure& obj)
{
	this->type = obj.getType();
	return (*this);
}

Cure::~Cure() {}

AMateria* Cure::clone() const
{
	return (new Cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
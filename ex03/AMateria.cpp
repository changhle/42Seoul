#include "AMateria.hpp"

AMateria::AMateria()
{
	type = "";
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria& obj)
{
	*this = obj;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
	this->type = obj.getType();
	return (*this);
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{

}
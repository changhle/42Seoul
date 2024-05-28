#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
		if (obj.inventory[i] != NULL)
			inventory[i] = obj.inventory[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
		if (obj.inventory[i] != NULL)
			inventory[i] = obj.inventory[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			std::cout << "learn : " << i << std::endl;
			inventory[i] = m;
			return ;
		}
		std::cout << "--------------" << i << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL && inventory[i]->getType() == type)
		{
			std::cout << "creat : " << i << std::endl;
			return (inventory[i]->clone());
		}
	}
	return (NULL);
}
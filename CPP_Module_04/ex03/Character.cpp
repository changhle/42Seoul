#include "Character.hpp"

Character::Character()
{
	name = "";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;	
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& obj)
{
	this->name = obj.getName();
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

Character& Character::operator=(const Character& obj)
{
	this->name = obj.getName();
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

Character::~Character()
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

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
			std::cout << i << std::endl;
		if (inventory[i] == NULL && m != NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
	{
		// delete inventory[idx];
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
		inventory[idx]->use(target);
}

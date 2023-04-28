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
	
}

Character::~Character()
{
	std::cout << "[Character] Destructor" << '\n';
}

Character& Character::operator=(const Character& obj)
{
	std::cout << "[Character] Copy assignment operator" << '\n';
	return (*this);

}
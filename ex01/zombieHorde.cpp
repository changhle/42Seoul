#include "Zombie.hpp"
#include <string>
#include <sstream>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie				*zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::stringstream	ss;
		ss << (i + 1);
		zombie[i].setName(name + "<" + ss.str() + ">");
	}
	return (zombie);
}
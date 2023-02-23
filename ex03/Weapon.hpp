#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string	weapon_type;

	public:
		Weapon(std::string weapon_type);
		void				setType(std::string weapon_type);
		const std::string	&getType();
		~Weapon();
};

#endif
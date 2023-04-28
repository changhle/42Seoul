#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character {
	private:
		AMateria*	inventory[4];
		std::string	name;
	public:
		Character();
		Character(std::string name);
		Character(const Character& obj);
		~Character();
		Character& operator=(const Character& obj);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif

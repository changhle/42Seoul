#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Default constructor" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::stringstream	ss;
		ss << i;
		ideas[i] = "bright idea" + ss.str();
	}
}

Brain::Brain(const Brain& obj) {
	std::cout << "Brain Copy constructor" << std::endl;
	*this = obj;
}

Brain& Brain::operator=(const Brain& obj) {
	std::cout << "Brain Copy assignment operator" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain Destructor" << std::endl;
}

std::string	Brain::getIdea(int	n) const
{
	return (ideas[n]);
}
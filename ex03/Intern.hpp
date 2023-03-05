#ifndef INTERN_CPP
#define INTERN_CPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:
		std::string	str[3];

	public:
		Intern();
		Intern(const Intern& obj);
		~Intern();
		Intern& operator=(const Intern& obj);
		Form*	makeForm(std::string form_name, std::string target_name);
		Form*	newShrubberyCreationForm(std::string& target);
		Form*	newRobotomyRequestForm(std::string& target);
		Form*	newPresidentialPardonForm(std::string& target);
};

#endif
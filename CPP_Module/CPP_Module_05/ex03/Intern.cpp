#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj) {
	(void)obj;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& obj) {
	(void)obj;
	return (*this);
}

Form* Intern::newShrubberyCreationForm(std::string& target){
	return (new ShrubberyCreationForm(target));
}

Form* Intern::newRobotomyRequestForm(std::string& target){
	return (new RobotomyRequestForm(target));
}

Form* Intern::newPresidentialPardonForm(std::string& target){
	return (new PresidentialPardonForm(target));
}

Form*	Intern::makeForm(std::string form_name, std::string target_name)
{
	Form* (Intern::*ret[3])(std::string& target) = {
 		&Intern::newShrubberyCreationForm, 
		&Intern::newRobotomyRequestForm, 
		&Intern::newPresidentialPardonForm
	};
	std::string str[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (form_name == str[i])
			return (this->*(ret[i]))(target_name);
	}
	throw std::string("I can't find that form_name");
}
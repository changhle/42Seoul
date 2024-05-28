#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45) {
	target = "default";	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45) {
	this->target = target;	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) :Form("RobotomyRequestForm", 72, 45) {
	target = obj.target;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	target = obj.target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const{
	if (getSigned() == true)
	{
		if (bureaucrat.getGrade() > getSignGrade())
			throw Form::GradeTooLowException();
		else if (bureaucrat.getGrade() < 1)
			throw Form::GradeTooHighException();
		else
		{
			std::cout << "Drrriiiiiilllllllll..." << std::endl;
			if (rand() % 2)
				std::cout << target << " has been robotomized successfully" << std::endl;
			else
				std::cout << target << " robotomy failed." << std::endl;
		}
	}
	else
		throw std::string("Form not signed");
}


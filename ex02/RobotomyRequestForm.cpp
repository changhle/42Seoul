#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestAForm::RobotomyRequestAForm() : AForm("RobotomyRequestAForm", 72, 45) {
	target = "default";	
}

RobotomyRequestAForm::RobotomyRequestAForm(std::string target) : AForm("RobotomyRequestAForm", 72, 45) {
	this->target = target;	
}

RobotomyRequestAForm::RobotomyRequestAForm(const RobotomyRequestAForm& obj) :AForm("RobotomyRequestAForm", 72, 45) {
	target = obj.target;
}

RobotomyRequestAForm::~RobotomyRequestAForm() {
}

RobotomyRequestAForm& RobotomyRequestAForm::operator=(const RobotomyRequestAForm& obj) {
	target = obj.target;
	return (*this);
}

void	RobotomyRequestAForm::execute(Bureaucrat const &bureaucrat) const{
	if (getSigned() == true)
	{
		if (bureaucrat.getGrade() > getSignGrade())
			throw AForm::GradeTooLowException();
		else if (bureaucrat.getGrade() < 1)
			throw AForm::GradeTooHighException();
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
		throw std::string("AForm not signed");
}


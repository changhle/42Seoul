#include "PresidentialPardonForm.hpp"

PresidentialPardonAForm::PresidentialPardonAForm() : AForm("PresidentialPardonAForm", 25, 5) {
	target = "default";
}

PresidentialPardonAForm::PresidentialPardonAForm(std::string target) : AForm("PresidentialPardonAForm", 25, 5) {
	this->target = target;	
}

PresidentialPardonAForm::PresidentialPardonAForm(const PresidentialPardonAForm& obj) :AForm("PresidentialPardonAForm", 25, 5) {
	target = obj.target;
}

PresidentialPardonAForm::~PresidentialPardonAForm() {
}

PresidentialPardonAForm& PresidentialPardonAForm::operator=(const PresidentialPardonAForm& obj) {
	target = obj.target;
	return (*this);
}

void	PresidentialPardonAForm::execute(Bureaucrat const &bureaucrat) const
{
	if (getSigned() == true)
	{
		if (bureaucrat.getGrade() > getExecuteGrade())
			throw AForm::GradeTooLowException();
		else if (bureaucrat.getGrade() < 1)
			throw AForm::GradeTooHighException();
		else
			std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
		throw std::string("AForm not signed");
}

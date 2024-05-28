#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5) {
	target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5) {
	this->target = target;	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) :Form("PresidentialPardonForm", 25, 5) {
	target = obj.target;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	target = obj.target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	if (getSigned() == true)
	{
		if (bureaucrat.getGrade() > getExecuteGrade())
			throw Form::GradeTooLowException();
		else if (bureaucrat.getGrade() < 1)
			throw Form::GradeTooHighException();
		else
			std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
		throw std::string("Form not signed");
}

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationAForm::ShrubberyCreationAForm() : AForm("ShrubberyCreationAForm", 145, 137) {
	target = "default";	
}

ShrubberyCreationAForm::ShrubberyCreationAForm(std::string target) : AForm("ShrubberyCreationAForm", 145, 137) {
	this->target = target;	
}

ShrubberyCreationAForm::ShrubberyCreationAForm(const ShrubberyCreationAForm& obj) :AForm("ShrubberyCreationAForm", 145, 137) {
	target = obj.target;
}

ShrubberyCreationAForm::~ShrubberyCreationAForm() {
}

ShrubberyCreationAForm& ShrubberyCreationAForm::operator=(const ShrubberyCreationAForm& obj) {
	target = obj.target;
	return (*this);
}

void	ShrubberyCreationAForm::execute(Bureaucrat const &bureaucrat) const
{
	if (getSigned() == true)
	{
		if (bureaucrat.getGrade() > getExecuteGrade())
			throw AForm::GradeTooLowException();
		else if (bureaucrat.getGrade() < 1)
			throw AForm::GradeTooHighException();
		else
		{
			std::ofstream output(target + "_shrubbery");
			output << ASCII_TREE;
			output.close();
		}
	}
	else
		throw std::string("AForm not signed");
}
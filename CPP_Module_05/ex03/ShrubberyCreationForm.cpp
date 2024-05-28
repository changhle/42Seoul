#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) {
	target = "default";	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137) {
	this->target = target;	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) :Form("ShrubberyCreationForm", 145, 137) {
	target = obj.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	target = obj.target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	if (getSigned() == true)
	{
		if (bureaucrat.getGrade() > getExecuteGrade())
			throw Form::GradeTooLowException();
		else if (bureaucrat.getGrade() < 1)
			throw Form::GradeTooHighException();
		else
		{
			std::ofstream output(target + "_shrubbery");
			output << ASCII_TREE;
			output.close();
		}
	}
	else
		throw std::string("Form not signed");
}
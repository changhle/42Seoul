#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name), _signed(false), signGrade(signGrade), executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& obj) : name(obj.name), _signed(obj._signed), signGrade(obj.signGrade), executeGrade(obj.executeGrade) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& obj) {
	const_cast<std::string &>(name) = obj.name;
	_signed = obj._signed;
	const_cast<int &>(signGrade) = obj.signGrade;
	const_cast<int &>(executeGrade) = obj.executeGrade;
	return (*this);
}

std::string	AForm::getName() const
{
	return (name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getSignGrade() const
{
	return (signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (executeGrade);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (signGrade >= bureaucrat.getGrade())
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &os, const AForm &AForm)
{
	os << "name : " << AForm.getName() << std::boolalpha << ", signed : " << AForm.getSigned() << " signGrade : " << AForm.getSignGrade() << " executeGrade : " << AForm.getExecuteGrade();
	return (os);
}
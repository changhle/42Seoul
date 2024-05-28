#include "Form.hpp"
#include "Bureaucrat.hpp"

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), _signed(false), signGrade(signGrade), executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& obj) : name(obj.name), _signed(obj._signed), signGrade(obj.signGrade), executeGrade(obj.executeGrade) {}

Form::~Form() {}

Form& Form::operator=(const Form& obj) {
	const_cast<std::string &>(name) = obj.name;
	_signed = obj._signed;
	const_cast<int &>(signGrade) = obj.signGrade;
	const_cast<int &>(executeGrade) = obj.executeGrade;
	return (*this);
}

std::string	Form::getName() const
{
	return (name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getSignGrade() const
{
	return (signGrade);
}

int	Form::getExecuteGrade() const
{
	return (executeGrade);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (signGrade >= bureaucrat.getGrade())
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &os, const Form &form)
{
	os << "name : " << form.getName() << std::boolalpha << ", signed : " << form.getSigned() << " signGrade : " << form.getSignGrade() << " executeGrade : " << form.getExecuteGrade();
	return (os);
}
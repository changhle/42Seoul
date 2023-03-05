#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

Bureaucrat::Bureaucrat() : name("default") {
	grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const  Bureaucrat& obj) : name(obj.name) {
	grade = obj.grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	const_cast<std::string &>(name) = obj.name;
	grade = obj.grade;
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::incrementGrade()
{
	grade--;
	if (grade < 1)
	{
		grade++;
		throw Bureaucrat::GradeTooHighException();
	}
}

void	Bureaucrat::decrementGrade()
{
	grade++;
	if (grade > 150)
	{
		grade--;
		throw Bureaucrat::GradeTooLowException();
	}
}

void	Bureaucrat::signAForm(AForm &AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << getName() << " signed " << AForm.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << getName() << " couldn't sign " << AForm.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeAForm(AForm const &AForm)
{
	try
	{
		AForm.execute(*this);
		std::cout << getName() << " executed " << AForm.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << getName() << " couldn't executed " << AForm.getName() << " because " << e.what() << std::endl;
	}
	catch(std::string &e)
	{
		std::cerr << getName() << " couldn't executed " << AForm.getName() << " because " << e << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string	name;
		bool				_signed;
		const int			signGrade;
		const int			executeGrade;
		AForm();

	public:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() ;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() ;
		};
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm& obj);
		~AForm();
		AForm& operator=(const AForm& obj);
		std::string		getName() const;
		bool			getSigned() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;
		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &bureaucrat) const = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm &AForm);

#endif

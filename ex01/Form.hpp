#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool				_signed;
		const int			signGrade;
		const int			executeGrade;
		Form();

	public:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() ;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() ;
		};
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form& obj);
		~Form();
		Form& operator=(const Form& obj);
		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		void		beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif

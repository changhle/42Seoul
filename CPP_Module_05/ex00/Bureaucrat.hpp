#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

	public:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() ;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() ;
		};
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const  Bureaucrat& obj);
		~Bureaucrat();
		Bureaucrat& operator=(const  Bureaucrat& obj);
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

#endif

#ifndef PRESIDENTIALPARDONAForm_HPP
#define PRESIDENTIALPARDONAForm_HPP

#include "AForm.hpp"

class PresidentialPardonAForm : public AForm {
	private:
		std::string	target;

	public:
		PresidentialPardonAForm();
		PresidentialPardonAForm(std::string target);
		PresidentialPardonAForm(const PresidentialPardonAForm& obj);
		~PresidentialPardonAForm();
		PresidentialPardonAForm& operator=(const PresidentialPardonAForm& obj);
		void	execute(Bureaucrat const &bureaucrat) const;
};

#endif

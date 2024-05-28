#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
	private:
		std::string	target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
		void	execute(Bureaucrat const &bureaucrat) const;
};

#endif

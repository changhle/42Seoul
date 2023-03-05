#ifndef ROBOTOMYREQUESTAForm_HPP
#define ROBOTOMYREQUESTAForm_HPP

#include "AForm.hpp"

class RobotomyRequestAForm : public AForm {
	private:
		std::string	target;

	public:
		RobotomyRequestAForm();
		RobotomyRequestAForm(std::string target);
		RobotomyRequestAForm(const RobotomyRequestAForm& obj);
		~RobotomyRequestAForm();
		RobotomyRequestAForm& operator=(const RobotomyRequestAForm& obj);
		void	execute(Bureaucrat const &bureaucrat) const;
};

#endif

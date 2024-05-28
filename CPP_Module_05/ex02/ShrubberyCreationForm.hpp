#ifndef SHRUBBERYCREATIONAForm_HPP
#define SHRUBBERYCREATIONAForm_HPP

#include "AForm.hpp"

#define ASCII_TREE "\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88\'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ \'|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_"

class ShrubberyCreationAForm : public AForm {
	private:
		std::string	target;

	public:
		ShrubberyCreationAForm();
		ShrubberyCreationAForm(std::string target);
		ShrubberyCreationAForm(const ShrubberyCreationAForm& obj);
		~ShrubberyCreationAForm();
		ShrubberyCreationAForm& operator=(const ShrubberyCreationAForm& obj);
		void	execute(Bureaucrat const &bureaucrat) const;
};

#endif

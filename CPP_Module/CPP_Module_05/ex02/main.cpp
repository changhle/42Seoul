#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void shrubberyTest()
{
	Bureaucrat bob("BOB", 4);
	Bureaucrat bob2("BOB", 138);
	ShrubberyCreationAForm test1("test1");
	ShrubberyCreationAForm test2("test2");
	std::cout << '\n';
	bob.signAForm(test1);
	bob.executeAForm(test1);
	std::cout << '\n';
	bob2.signAForm(test2);
	bob2.executeAForm(test2);
	std::cout << '\n';
}

void roboTest()
{
	Bureaucrat bob("BOB", 4);
	Bureaucrat bob2("BOB2", 138);
	RobotomyRequestAForm test1("test1");
	RobotomyRequestAForm test2("test2");
	std::cout << '\n';
	bob.signAForm(test1);
	bob.executeAForm(test1);
	std::cout << '\n';
	bob2.signAForm(test2);
	bob2.executeAForm(test2);
	std::cout << '\n';
}

void presidentTest()
{
	Bureaucrat bob("BOB", 4);
	Bureaucrat bob2("BOB", 138);
	PresidentialPardonAForm test1("test1");
	PresidentialPardonAForm test2("test2");
	std::cout << '\n';
	bob.signAForm(test1);
	bob.executeAForm(test1);
	std::cout << '\n';
	bob2.signAForm(test2);
	bob2.executeAForm(test2);
	std::cout << '\n';
}



int main(){
	std::cout << "====== ShrubberyCreationAForm Test =====" << '\n';	
	shrubberyTest();
	std::cout << '\n';
	std::cout << "====== RobotomyRequestAForm Test =====" << '\n';	
	roboTest();
	std::cout << '\n';
	std::cout << "====== PresidentialPardonAForm Test =====" << '\n';	
	presidentTest();
	std::cout << '\n';
}
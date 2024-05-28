#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat bob("bob", 4);
	Intern intern;
	Intern intern2;
	Form* test1;
	Form* test2;

	test1 = intern.makeForm("presidential pardon", "Bender");
	bob.signForm(*test1);
	bob.executeForm(*test1);

	std::cout << '\n';
	try
	{
		test2 = intern2.makeForm("robotomy", "Bender");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
	}
}
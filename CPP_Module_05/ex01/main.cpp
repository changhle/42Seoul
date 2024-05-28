#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Form("exception", 1, 200);
		Form("exception", 0, 150);
		Form("exception", 0, 200);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat	b("b", 50);
	Form		f1("f1", 10, 10);
	Form		f2("f2", 60, 60);

	// b.signForm(f1);
	std::cout << b << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << std::endl;
	
	b.signForm(f2);
}
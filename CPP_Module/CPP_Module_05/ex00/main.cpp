#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat("exception", 200);
		// Bureaucrat(Bureaucrat("exception", 0));
		// Bureaucrat	a;
		// a = Bureaucrat("exception", 200);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat	a("a", 1);
		Bureaucrat	b("b", 150);

		// a.incrementGrade();
		// b.decrementGrade();

		a.decrementGrade();
		b.incrementGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
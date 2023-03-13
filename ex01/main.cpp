#include "Span.hpp"

int	main()
{
	Span	sp = Span(5);
	std::cout << std::endl;

	try
	{
		sp.addNumber(3);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		sp.addNumber(7);
		sp.addNumber(13);
		sp.addNumber(20);
		sp.addNumber(25);
		sp.addNumber(40);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	std::cout << std::endl;

	std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest  : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}
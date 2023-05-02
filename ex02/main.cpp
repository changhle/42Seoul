#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	pmg;

	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		if (pmg.checkArg(argv[i]))
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
	}
	try
	{
		for (int i = 1; i < argc; i++)
			pmg.insertArg(argv[i]);
		pmg.sortSimulator();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	
}
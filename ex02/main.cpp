#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	pmg;

	if (argc < 2)
	{
		std::cout << "Argument Error!" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
		pmg.insertArg(argv[i]);
	pmg.sortSimulator();
}
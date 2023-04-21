#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	rpn;

	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	rpn.simulateRpn(argv[1]);
	return (0);
}
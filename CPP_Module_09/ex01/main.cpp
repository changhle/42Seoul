#include "Rpn.hpp"

int	main(int argc, char **argv)
{
	Rpn	Rpn;

	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	Rpn.simulateRpn(argv[1]);
	return (0);
}
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Plese input argument [Number, inf, -inf, nan ..." << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	std::cout << std::endl;
}
#include "BitcoinExchange.hpp"

void	printError(std::string str)
{
	std::cout << "Error: " << str << std::endl;

}

int	main(int argc, char **argv)
{
	BitcoinExchange	btc;

	try
	{
		if (argc != 2)
			throw std::invalid_argument("Error: could not open file.");
		std::ifstream	input(argv[1]);
		btc.storeDefaultDatabase();
		btc.showInputDatabase(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

}
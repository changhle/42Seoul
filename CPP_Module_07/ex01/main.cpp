#include "iter.hpp"

int main()
{
	int			intArr[5] = {1, 2, 3, 4, 5};
	std::string	stringArr[3] = {"apple", "banna", "orange"};

	iter<int>(intArr, 5, print<int>);
	std::cout << std::endl;
	iter<int>(intArr, 5, print);
	std::cout << std::endl;
	iter(intArr, 5, print);
	std::cout << std::endl;
	iter(intArr, 5, pow);
	for (int i = 0; i < 5; i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	iter<std::string>(stringArr, 3, print<std::string>);
	std::cout << std::endl;
	iter<std::string>(stringArr, 3, print);
	std::cout << std::endl;
	iter(stringArr, 3, print);
	std::cout << std::endl;
}
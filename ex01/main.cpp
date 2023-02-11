#include "PhoneBook.hpp"

int	main()
{
	std::string	input;
	PhoneBook	pb;

	while (42)
	{
		std::cout << "Prompt : ";
		std::cin >> input;
		if (input.compare("ADD") == 0)
			pb.add();
		else if (input.compare("SEARCH") == 0)
			pb.search();
		else if (input.compare("EXIT") == 0)
			break;
	}
}
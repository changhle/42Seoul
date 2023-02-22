#include "PhoneBook.hpp"
#include <string>

std::string	cmd_input()
{
	std::string	cmd;
	int			i;

	std::cout << "Prompt : ";
	getline(std::cin, cmd);
	i = 0;
	while (cmd[i])
	{
		cmd[i] = static_cast<char>(std::toupper(cmd[i]));
		i++;
	}
	return (cmd);
}

int	main()
{
	std::string	cmd;
	PhoneBook	pb;

	while (42)
	{
		cmd = cmd_input();
		if (cmd == "ADD")
			pb.add();
		else if (cmd == "SEARCH")
			pb.search();
		else if (std::cin.eof() || cmd == "EXIT")
			break;
		else
			std::cout << "Non-Existent Commands!" << std::endl;
	}
}
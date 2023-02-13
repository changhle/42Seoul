#include "PhoneBook.hpp"

int	cmd_input()
{
	std::string	cmd;
	int			cmd_type;
	int			i;

	std::cout << "Prompt : ";
	std::cin >> cmd;
	i = 0;
	while (cmd[i])
	{
		cmd[i] = static_cast<char>(std::toupper(cmd[i]));
		i++;
	}
	if (cmd == "ADD")
		cmd_type = ADD;
	else if (cmd == "SEARCH")
		cmd_type = SEARCH;
	if (cmd == "EXIT")
		cmd_type = EXIT;
	return (cmd_type);	
}

int	main()
{
	int			cmd_type;
	PhoneBook	pb;

	while (42)
	{
		cmd_type = cmd_input();
		switch (cmd_type)
		{
		case ADD:
			pb.add();
			break;
		case SEARCH:
			pb.search();
		case EXIT:
			return (0);
		default:
			break;
		}
	}
}
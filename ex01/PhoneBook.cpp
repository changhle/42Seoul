#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

void	PhoneBook::add()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "First name : ";
	std::cin >> first_name;
	std::cout << "Last name : ";
	std::cin >> last_name;
	std::cout << "Nickname : ";
	std::cin >> nickname;
	std::cout << "Phone number : ";
	std::cin >> phone_number;
	std::cout << "Darkest secret : ";
	std::cin >> darkest_secret;
	contact[index % 8] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	index++;
}

void	PhoneBook::search()
{
	int	i;
	int	input;

	i = 0;
	while (i < index)
	{
		std::cout << i << std::endl;
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << contact[i].get_first_name() << "|";
		std::cout << std::setw(10) << contact[i].get_last_name() << "|";
		std::cout << std::setw(10) << contact[i].get_nickname() << std::endl;
		i++;
		if (i == 8)
			break;
	}
	std::cout << "Index : ";
	std::cin >> input;
	if (input > 7 || input > index)
		std::cout << "Out of range!" << std::endl;
	else
	{
		std::cout << contact[i]
	}
}
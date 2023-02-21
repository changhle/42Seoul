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
	getline(std::cin, first_name);
	std::cout << "Last name : ";
	getline(std::cin, last_name);
	std::cout << "Nickname : ";
	getline(std::cin, nickname);
	std::cout << "Phone number : ";
	getline(std::cin, phone_number);
	std::cout << "Darkest secret : ";
	getline(std::cin, darkest_secret);
	std::cout << std::endl;
	contact[index % 8] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	index++;
}

void	PhoneBook::search()
{
	int	i;
	int	input;

	if (index == 0)
	{
		std::cout << "No contact!" << std::endl;
		return;
	}
	i = 0;
	while (i < index)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << contact[i].get_first_name() << "|";
		std::cout << std::setw(10) << contact[i].get_last_name() << "|";
		std::cout << std::setw(10) << contact[i].get_nickname() << std::endl;
		i++;
		if (i == 8)
			break;
	}
	std::cout << "\nIndex : ";
	std::cin >> input;
	if (std::cin.fail() || input > 7 || input + 1 > index)
	{
		std::cin.clear();
		std::cout << "Out of range!" << std::endl;
	}
	else
	{
		std::cout << "First name : " << contact[input].get_first_name() << std::endl;
		std::cout << "Last name : " << contact[input].get_last_name() << std::endl;
		std::cout << "Nickname : " << contact[input].get_nickname() << std::endl;
		std::cout << "Phone number : " << contact[input].get_phone_number() << std::endl;
		std::cout << "Darkest secret : " << contact[input].get_darkest_secret() << std::endl << std::endl;
	}
	std::cin.ignore(100, '\n');
}
#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

std::string	cut_string(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void	ft_getline(std::string&str)
{
	getline(std::cin, str);
	if (std::cin.eof())
		std::exit(0);
}

void	PhoneBook::add()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "First name : ";
	ft_getline(first_name);
	std::cout << "Last name : ";
	ft_getline(last_name);
	std::cout << "Nickname : ";
	ft_getline(nickname);
	std::cout << "Phone number : ";
	ft_getline(phone_number);
	std::cout << "Darkest secret : ";
	ft_getline(darkest_secret);
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
	while (42)
	{
		i = 0;
		while (i < index)
		{
			std::cout << std::setw(10) << i << "|";
			std::cout << std::setw(10) << cut_string(contact[i].get_first_name()) << "|";
			std::cout << std::setw(10) << cut_string(contact[i].get_last_name()) << "|";
			std::cout << std::setw(10) << cut_string(contact[i].get_nickname()) << std::endl;
			i++;
			if (i == 8)
				break;
		}
		std::cout << "\nIndex : ";
		std::cin >> input;
		if (std::cin.eof())
			std::exit(0);
		else if (std::cin.fail() || input > 7 || input + 1 > index)
		{
			std::cin.clear();
			std::cout << "Out of range!" << std::endl;
			std::cin.ignore(100, '\n');
		}
		else
		{
			std::cout << "First name : " << contact[input].get_first_name() << std::endl;
			std::cout << "Last name : " << contact[input].get_last_name() << std::endl;
			std::cout << "Nickname : " << contact[input].get_nickname() << std::endl;
			std::cout << "Phone number : " << contact[input].get_phone_number() << std::endl;
			std::cout << "Darkest secret : " << contact[input].get_darkest_secret() << std::endl << std::endl;
			std::cin.ignore(100, '\n');
			return;
		}
	}
}
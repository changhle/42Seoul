#include "BitcoinExchange.hpp"

void	BitcoinExchange::storeDefaultDatabase()
{
	std::ifstream	input("data.csv");
	std::string		line;
	std::string		date;
	std::string		rate;
	unsigned long	pos;
	double			double_rate;

	if (!input.is_open())
		throw std::invalid_argument("Error: could not open file.");
	getline(input, line);
	while (!input.eof())
	{
		getline(input, line);
		pos = line.find(',');
		if (pos != std::string::npos)
		{
			date = line.substr(0, pos);
			rate = line.substr(pos + 1, line.length() - pos - 1);
		}
		std::stringstream	ss(rate);
		ss >> double_rate;
		m.insert(std::pair<std::string, double>(date, double_rate));
	}
}

void	BitcoinExchange::showInputDatabase(std::string input_file_name)
{
	std::ifstream	input(input_file_name);
	std::string		line;
	std::string		date;
	std::string		value;
	unsigned long	pos;
	double			value_double;

	if (!input.is_open())
		throw std::invalid_argument("Error: could not open file.");
	getline(input, line);
	while (!input.eof())
	{
		getline(input, line);
		pos = line.find('|');
		if (pos != std::string::npos)
		{
			date = line.substr(0, pos - 1);
			value = line.substr(pos + 2, line.length() - pos - 2);
			if (isValidDate(date))
				std::cout << "Error: bad input => " << date << std::endl;
			else
			{
				std::stringstream	ss(value);
				ss >> value_double;
				calculateValue(date, value_double);
			}
		}
		else
			std::cout << "Error: bad input => " << line << std::endl;
	}	
}

int	BitcoinExchange::isValidDate(std::string date)
{
	int	i = 0;

	while (date[i])
	{
		if (!std::isdigit(date[i]) && i != 4 && i != 7)
			return (1);
		else if (date[i] != '-' && (i == 4 || i == 7))
			return (1);
		i++;
	}
	if (i != 10)
		return (1);
	return (0);
}

void	BitcoinExchange::calculateValue(std::string date, double value)
{
	std::map<std::string, double>::iterator	it;
	double		data_rate = 0;

	for (it = m.begin(); it != m.end(); it++)
	{
		if ((*it).first >= date)
		{
			if ((*it).first == date)
				data_rate = (*it).second;
			else
			{
				if (it == m.begin())
					std::cout << "Error: bad input => " << date << std::endl;
				else
					data_rate = (*--it).second;
			}
			if (value > INT_MAX)
				std::cout << "Error: too large a number." << std::endl;
			else if (value >= 0)
				std::cout << date << " => " << value << " = " << data_rate * value << std::endl;
			else
				std::cout << "Error: not a positive number." << std::endl;
			return;
		}
	}
}

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
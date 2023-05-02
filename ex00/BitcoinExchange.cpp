#include "BitcoinExchange.hpp"

void	BitcoinExchange::storeDefaultDatabase()
{
	std::ifstream	input("data.csv");
	std::string		line;
	std::string		date;
	std::string		rate;
	unsigned long	pos;
	double			double_rate = 0;

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
		if (!isValidDate(date) && !isValidValue(rate))
		{
			std::stringstream	ss(rate);
			ss >> double_rate;
			m[date] = double_rate;
		}
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
			if (isValidDate(date) || isValidValue(value))
				std::cout << "Error: bad input => " << date << std::endl;
			else
			{
				std::stringstream	ss(value);
				ss >> value_double;
				if (value_double >= 1000)
					std::cout << "Error: too large a number." << std::endl;
				else if (value_double <= 0)
					std::cout << "Error: not a positive number." << std::endl;
				else
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
	int	i_year, i_month, i_day;
	std::string	year, month, day;

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
	year = date.substr(0, 4);
	month = date.substr(5, 2);
	day = date.substr(8, 2);
	std::stringstream	ss_year(year), ss_month(month), ss_day(day);
	ss_year >> i_year;
	ss_month >> i_month;
	ss_day >> i_day;
	if (i_year < 1 || (i_month < 1 || i_month > 12) || (i_day < 1 || i_day > 31))
		return (1);
	if ((i_month < 8 && i_month % 2 == 0 && i_day > 30)
		|| (i_month > 7 && i_month % 2 == 1 && i_day > 30))
		return (1);
	if (i_month == 2)
	{
		if (i_year % 4 == 0 && (i_year % 400 == 0 || i_year % 100 != 0) && i_day > 29)
			return (1);
		else if (!(i_year % 4 == 0 && (i_year % 400 == 0 || i_year % 100 != 0)) && i_day > 28)
			return (1);
	}
	return (0);
}

int	BitcoinExchange::isValidValue(std::string value)
{
	int	i;

	i = 0;
	if (value.length() == 0)
		return (1);
	while (value[i])
	{
		if (!std::isdigit(value[i]) && value[i] != '.' && value[i] != '+' && value[i] != '-')
			return (1);
		i++;
	}
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
			{
				data_rate = (*it).second;
				std::cout << std::setprecision(10) << date << " => " << value << " = " << data_rate * value << std::endl;
			}
			else if (it == m.begin())
				std::cout << "Error: bad input => " << date << std::endl;
			else
			{
				data_rate = (*--it).second;
				std::cout << std::setprecision(10) << date << " => " << value << " = " << data_rate * value << std::endl;
			}
			return;
		}
	}
	if (it == m.end())
		std::cout << std::setprecision(10) << date << " => " << value << " = " << (*--it).second * value << std::endl;
}

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
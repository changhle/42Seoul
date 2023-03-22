#include "BitcoinExchange.hpp"

void	BitcoinExchange::storeDataBase()
{
	std::string		date;
	std::string		rate;
	int				int_rate;
	std::ifstream	input("data.csv");

	if (!input.is_open())
		throw std::invalid_argument("Can not open data file");
	
	getline(input, date);
	// std::cout << "{" << (*m.begin()).first << ": " << (*m.begin()).second << "}\n";
	m.clear();
	while (!input.eof())
	{
		getline(input, date, ',');
		if (date.length() != 10)
			break;
		// std::cout << date << std::endl;
		getline(input, rate);
		// std::cout << rate << std::endl;
		std::stringstream	ss(rate);
		ss >> int_rate;
		m.insert(std::pair<std::string, int>(date, int_rate));
		// std::cout << "{" << (*m.begin()).first << ": " << (*m.begin()).second << "}\n";
		// std::cout << "{" << (*(--m.end())).first << ": " << (*(--m.end())).second << "}\n";
	}
}
#include <iterator>
void	BitcoinExchange::showDataBase()
{
	std::map<std::string, int>::iterator	it;
	
	for (it = m.begin(); it != m.end(); ++it) {
        std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
    }
}



BitcoinExchange::BitcoinExchange()
{
	std::cout << "[BitcoinExchange] Default constructor" << std::endl;
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
// {
// 	std::cout << "[BitcoinExchange] Copy constructor" << std::endl;
// }

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "[BitcoinExchange] Destructor" << std::endl;
}

// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
// {
// 	std::cout << "[BitcoinExchange] Copy assignment operator" << std::endl;
// 	return (*this);

// }
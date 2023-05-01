#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double>	m;
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		int		isValidDate(std::string date);
		int		isValidValue(std::string value);
		void	calculateValue(std::string date, double value);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void	storeDefaultDatabase();
		void	showInputDatabase(std::string input_file_name);
};

#endif

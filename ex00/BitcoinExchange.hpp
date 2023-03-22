#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, int>	m;
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void	storeDataBase();
		void	showDataBase();
};

#endif

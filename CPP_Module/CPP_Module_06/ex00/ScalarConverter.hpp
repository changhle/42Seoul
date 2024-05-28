#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& obj);

	public:
		static void	convert(std::string str);
		static void	printChar(double value, bool flag);
		static void	printInt(double value, bool flag);
		static void	printFloat(double value, bool flag);
		static void	printDouble(double value, bool flag);
		static bool	isNanDouble(double value);
		static bool	isinfDouble(double value);
};

#endif

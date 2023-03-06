#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string str)
{
	double	value;
	bool	flag = false;
	char	*ptr;

	if (str.length() == 1 && std::isalpha(str[0]))
	{
		std::cout << "char : " << str << std::endl;
		std::cout << "int : " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float : " << static_cast<float>(str[0]) << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(str[0]) << ".0" << std::endl;
		return;
	}
	value = std::strtod(str.c_str(), &ptr);
	if (isNanDouble(value) || isinfDouble(value))
		flag = true;
	if ((value == 0 && !std::isdigit(str[0])) || (*ptr && strcmp(ptr, "f")))
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
		return;
	}
	printChar(value, flag);
	printInt(value, flag);
	printFloat(value, flag);
	printDouble(value, flag);
}

void	ScalarConverter::printChar(double value, bool flag)
{
	std::cout << "char : ";
	if (value < 0 || value > 126 || flag)
		std::cout << "impossible" << std::endl;
	else if (value >= 0 && value <= 31)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(value) << std::endl;
}

void	ScalarConverter::printInt(double value, bool flag)
{
	std::cout << "int : ";
	if (value < INT_MIN || value > INT_MAX || flag)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::printFloat(double value, bool flag)
{
	std::cout << "float : ";
	if (flag)
		std::cout << std::showpos << value << "f" << std::endl;
	else if (value < INT_MIN || value > INT_MAX)
		std::cout << "impossible" << std::endl;
	else if (value == static_cast<long long>(value))
		std::cout << value << ".0f" << std::endl;
	else
		std::cout << static_cast<float>(value) << std::endl;
}

void	ScalarConverter::printDouble(double value, bool flag)
{
	std::cout << "double : ";
	if (flag)
		std::cout << std::showpos << value << std::endl;
	else if (value < INT_MIN || value > INT_MAX)
		std::cout << "impossible" << std::endl;
	else if (value == static_cast<long long>(value))
		std::cout << value << ".0" << std::endl;
	else
		std::cout << value << std::endl;
}

bool	ScalarConverter::isNanDouble(double value)
{
	return (value != value);
}

bool	ScalarConverter::isinfDouble(double value)
{
	return (value * 2 == value && value != 0);
}
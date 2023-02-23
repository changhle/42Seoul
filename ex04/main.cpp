#include "StringReplace.hpp"
#include <fstream>
#include <string>

std::string	readFileContent(std::ifstream &input)
{
	std::string	str;
	std::string	buf;

	while (!input.eof())
	{
		getline(input, buf);
		if (buf.length() != 0)
		{
			str += buf;
			if (!input.eof())
				str += "\n";
		}
	}
	return (str);
}

std::string	replaceString(std::string from, std::string to, std::string str)
{
	std::string	sub_str;
	size_t		pos;

	while (42)
	{
		pos = str.find(from);
		if (pos == std::string::npos)
			break;
		sub_str = substr(0, )
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Argument error!" << std::endl;
		return (1);
	}
	std::ifstream	input(argv[1]);
	if (!input.is_open())
	{
		std::cout << "File open error!" << std::endl;
		return (1);
	}
	replaceString(argv[2], argv[3], readFileContent(input));
}
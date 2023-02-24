#include <iostream>
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
			str += buf;
		if (!input.eof())
			str += "\n";
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
		sub_str = str.substr(0, pos);
		sub_str += to;
		sub_str += str.substr(pos + from.length(), str.length() - (pos + from.length()));
		str = sub_str;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	std::string	fileName(argv[1]);

	if (argc != 4)
	{
		std::cout << "Argument error!" << std::endl;
		return (1);
	}
	std::ifstream	input(fileName);
	std::ofstream	output(fileName + ".replace");
	if (!input.is_open() || !output.is_open())
	{
		std::cout << "File open error!" << std::endl;
		return (1);
	}
	output << replaceString(argv[2], argv[3], readFileContent(input));
	return (0);
}
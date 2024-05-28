#include "Harl.hpp"

Harl::Harl() {
	levelStr[DEBUG] = "DEBUG";
	f[DEBUG] = &Harl::debug;
	levelStr[INFO] = "INFO";
	f[INFO] = &Harl::info;
	levelStr[WARNING] = "WARNING";
	f[WARNING] = &Harl::warning;
	levelStr[ERROR] = "ERROR";
	f[ERROR] = &Harl::error;
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (level == levelStr[i])
			break;
	}
	switch (i)
	{
	case DEBUG:
		(this->*f[DEBUG])();
	case INFO:
		(this->*f[INFO])();
	case WARNING:
		(this->*f[WARNING])();
	case ERROR:
		(this->*f[ERROR])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}



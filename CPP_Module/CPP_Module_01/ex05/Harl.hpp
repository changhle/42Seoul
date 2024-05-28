#ifndef HARL_HPP
#define HARL_HPP

#define DEBUG	0
#define INFO	1
#define WARNING	2
#define ERROR	3

#include <iostream>

class Harl {
	private:
		std::string	levelStr[4];
		void		(Harl::*f[4])(void);
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl();
		void	complain(std::string level);
};

#endif
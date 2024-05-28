#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

class Rpn {
	private:
		std::stack<double>	stack;
		double	operand_a;
		double	operand_b;
		Rpn(const Rpn& obj);
		Rpn& operator=(const Rpn& obj);
		double	calculate(char oper);

	public:
		Rpn();
		~Rpn();
		void	simulateRpn(char *expr);

};

#endif

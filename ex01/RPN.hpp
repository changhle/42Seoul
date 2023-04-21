#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

class RPN {
	private:
		std::stack<double>	stack;
		double	operand_a;
		double	operand_b;
		RPN(const RPN& obj);
		RPN& operator=(const RPN& obj);
		double	calculate(char oper);

	public:
		RPN();
		~RPN();
		void	simulateRpn(char *expr);

};

#endif


// RPN::RPN(const RPN& obj) {
// 	std::cout << "[RPN] Copy constructor" << '\n';
// }
// RPN& RPN::operator=(const RPN& obj) {
// 	std::cout << "[RPN] Copy assignment operator" << '\n';
// 	return (*this);
// }
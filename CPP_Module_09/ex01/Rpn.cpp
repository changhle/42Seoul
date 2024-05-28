#include "Rpn.hpp"

Rpn::Rpn() {}
Rpn::~Rpn() {}

void	Rpn::simulateRpn(char *expr)
{
	std::string		oper = "+-*/";
	int				i;

	i = 0;
	while (expr[i])
	{
		if (std::isdigit(expr[i]))
			stack.push(expr[i] - '0');
		else if (oper.find(expr[i]) != std::string::npos)
		{
			if (stack.size() >= 2)
			{
				operand_b = stack.top();
				stack.pop();
				operand_a = stack.top();
				stack.pop();
				stack.push(calculate(expr[i]));
			}
			else
			{
				std::cout << "Error" << std::endl;
				return;
			}
		}
		else if (expr[i] != ' ')
		{
			std::cout << "Error" << std::endl;
			return;
		}
		i++;
	}
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
	{
		std::cout << "Error" << std::endl;
		return;
	}
}

double	Rpn::calculate(char oper)
{
	if (oper == '+')
		return (operand_a + operand_b);
	else if (oper == '-')
		return (operand_a - operand_b);
	else if (oper == '*')
		return (operand_a * operand_b);
	else
		return (operand_a / operand_b);
}

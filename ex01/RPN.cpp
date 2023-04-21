#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

void	RPN::simulateRpn(char *expr)
{
	std::string		oper = "+-*/";
	int				i;

	i = 0;
	while (expr[i])
	{
		if (expr[i] >= '0' && expr[i] <= '9')
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
				std::cerr << "Error" << std::endl;
				return;
			}
		}
		else if (expr[i] != ' ')
		{
			std::cerr << "Error" << std::endl;
			return;
		}
		i++;
	}
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
	{
		std::cerr << "Error" << std::endl;
		return;
	}
}

double	RPN::calculate(char oper)
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

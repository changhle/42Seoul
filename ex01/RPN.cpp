#include "RPN.hpp"

double	calculate(double operand_a, double operand_b, char oper)
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

void	RPN(char *expr)
{
	std::stack<double>	stack;
	std::string		oper = "+-*/";
	double			operand_a;
	double			operand_b;
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
				stack.push(calculate(operand_a, operand_b, expr[i]));
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
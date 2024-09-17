
#include "RPN.hpp"

void RPN(char * input)
{
	std::stack<int>	stack;
	int		first;
	int		second;
	int		result = 0;
	
	int		digit = 0;
	int		sign = 0;

	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == ' ')
			i++;
		if (isdigit(input[i]))
			digit++;
		else if ((input[i]) == '*' || (input[i]) == '/' || (input[i]) == '+' || (input[i]) == '-')
			sign++;
	}
	if (sign != digit - 1)
		throw std::runtime_error("Error syntax: You must have one digit more than signs.");

	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == ' ')
			i++;
		if (isdigit(input[i]))
			stack.push(input[i] - '0');
		else if ((input[i]) == '*' || (input[i]) == '/' || (input[i]) == '+' || (input[i]) == '-')
		{
			second = stack.top();
			stack.pop();
			first = stack.top();
			stack.pop();
			switch (input[i])
			{
			case '*':
				result = first * second;
				break;
			case '/':
				result = first / second;
				break;
			case '+':
				result = first + second;
				break;
			case '-':
				result = first - second;
			default:
				break;
			}
			stack.push(result);
		}
		else
		{
			std::cout << "Error." << std::endl;
			return;
		}
	}
	std::cout << result << std::endl;
}

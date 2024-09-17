
#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Usage: ./RPN \"expression\"" << std::endl;
		return(1);
	}

	try
	{
		RPN(av[1]);
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::vector<int>	input;

	if (ac < 3)
		return std::cout << "Error: Usage: ./sort [int sequence]" << std::endl, 1;
	
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
			if (!isdigit(av[i][j]))
				return std::cout << "Error." << std::endl, 1;
		int nb = atoi(av[i]);
		if (nb < 0)
			return std::cout << "Error." << std::endl, 1;
		input.push_back(nb);
	}

	std::cout << "Before: ";
	for (std::vector<int>::iterator	it = input.begin(); it != input.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
	
	std::deque<int>		deque(input.begin(), input.end());
	vecSort(input);
	listSort(deque);
}
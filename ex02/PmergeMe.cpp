#include "PmergeMe.hpp"

bool	isDuplicate(int num, int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == num)
			return false;
	}
	return true;
}

bool	isNumber(char *arg)
{
	for (size_t j = 0; j < std::strlen(arg); ++j)
	{
		if (!std::isdigit(arg[j]))
			return false;
	}
	return true;
}

bool	isValid(int argc, char *argv[])
{
	if (argc < 2)
		return std::cerr << "Usage: " << argv[0] << " [num...]" << std::endl, false;
	int numbers[argc - 1];
	int count = 0;

	for (int i = 1; i < argc; ++i)
	{
		char *arg = argv[i];

		if (!isNumber(arg))
			return std::cerr << "Error: Characters include." << std::endl, false;

		long num = std::atol(arg);
		if (num > INT_MAX || num < 0)
			return std::cerr << "only positive integer sequence as argument." << std::endl, false;

		if (!isDuplicate(num, numbers, count))
			return std::cerr << "Error: There are duplicate numbers." << std::endl, false;

		numbers[count] = static_cast<int>(num);
		++count;
	}
	return true;
}

void	mergeInsertionSort(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return;
	std::vector<int> larger, smaller;

	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (i + 1 < arr.size())
		{
			larger.push_back(std::max(arr[i], arr[i + 1]));
			smaller.push_back(std::min(arr[i], arr[i + 1]));
		}
		else
			larger.push_back(arr[i]);
	}
	mergeInsertionSort(larger);
	arr.clear();
	arr = larger;
	for (size_t i = 0; i < smaller.size(); ++i)
	{
			std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), smaller[i]);
			arr.insert(it, smaller[i]);
	}
}

void	mergeInsertionSort(std::list<int>& arr)
{
	if (arr.size() <= 1)
		return;

	std::list<int> larger, smaller;
	std::list<int>::iterator it = arr.begin();
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (i + 1 < arr.size())
		{
			int first = *it++;
			int second = *it++;
			larger.push_back(std::max(first, second));
			smaller.push_back(std::min(first, second));
		}
		else
			larger.push_back(*it++);
	}
	mergeInsertionSort(larger);

	arr.clear();
	arr = larger;

	for (std::list<int>::iterator it = smaller.begin(); it != smaller.end(); ++it)
	{
		std::list<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), *it);
		arr.insert(pos, *it);
	}
}
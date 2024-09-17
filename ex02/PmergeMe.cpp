#include "PmergeMe.hpp"

void vecSort(std::vector<int> & input)
{	
	clock_t start = clock();
	
	size_t const				half_size = input.size() / 2;
	std::vector<int>			split_lo(input.begin(), input.begin() + half_size);
	std::vector<int>			split_hi(input.begin() + half_size, input.end());

	std::vector<int>::iterator	it;
	std::vector<int>::iterator	ite;

	std::sort(split_lo.begin(), split_lo.end());
	std::sort(split_hi.begin(), split_hi.end());

	split_lo.insert(split_lo.end(), split_hi.begin(), split_hi.end());

	std::sort(split_lo.begin(), split_lo.end());
	
	std::cout << "After: ";
	for (it = split_lo.begin(), ite = split_lo.end(); it != ite; it++)
		std::cout << " " << *it;
	std::cout << std::endl;

	clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << input.size() << " elements with std::vector<int> : " << duration << " us" << std::endl;
}

void listSort(std::deque<int>	&deque)
{
	clock_t start = clock();
	
	std::deque<int>::iterator	it = deque.begin();
	std::deque<int>::iterator	ite = deque.end();

	size_t const				half_size = deque.size() / 2;
	std::deque<int>				split_lo;
	std::deque<int>				split_hi;

	for (size_t i = 0; i < half_size; i++)
	{
		split_lo.push_back(*it);
		it++;
	}
	for (; it != ite; it++)
		split_hi.push_back(*it);

	std::sort(split_lo.begin(), split_lo.end());
	std::sort(split_hi.begin(), split_hi.end());

	split_lo.insert(split_lo.end(), split_hi.begin(), split_hi.end());

	std::sort(split_lo.begin(), split_lo.end());

	clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque<int> : " << duration << " us" << std::endl;
}
#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
	if (!isValid(argc, argv))
		return 1;
	std::vector<int> vec;
	for (int i = 1; i < argc; ++i)
		vec.push_back(std::atoi(argv[i]));
	std::cout << "Before:\t";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	std::clock_t start = std::clock();
	mergeInsertionSort(vec);
	std::clock_t end = std::clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "After:\t";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "  <<
	std::fixed << std::setprecision(6) << elapsed_time << " sec"
	<< std::endl;


	std::list<int> lst;
	for (int i = 1; i < argc; ++i)
		lst.push_back(std::atoi(argv[i]));
	start = std::clock();
	mergeInsertionSort(lst);
	end = std::clock();
	elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << lst.size() << " elements with std::list : "  <<
	std::fixed << std::setprecision(6) << elapsed_time << " sec"
	<< std::endl;
}

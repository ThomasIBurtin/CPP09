#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>
#include <list>
#include <climits>
		
void	mergeInsertionSort(std::vector<int>& arr);
void	mergeInsertionSort(std::list<int>& arr);
bool	isDuplicate(int num, int arr[], int size);
bool	isNumber(char *arg);
bool	isValid(int argc, char *argv[]);

#endif

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>

extern double ELAPSED_VECTOR;
extern double ELAPSED_DEQUE;

bool isPositiveInteger(std::string input);
int jacobsthal(int n);
std::vector<int> mergeInsertionSort(std::vector<int>& numbers);
std::deque<int> mergeInsertionSortDeque(std::deque<int>& numbers);

#endif
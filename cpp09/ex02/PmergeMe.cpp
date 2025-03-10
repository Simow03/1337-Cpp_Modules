#include "PmergeMe.hpp"

bool isPositiveInteger(std::string input) {

    for (size_t i = 0; i < input.length(); i++) {
        if ((!isdigit(input[i]) && input[i] != '+') || (input[i] == '+' && i != 0))
            return false;
    }

    if (input.length() > 1 && input[0] == '0')
        return false;

    double value = std::strtod(input.c_str(), NULL);

    if (value > INT_MAX)
        return false;

    return true;
}

std::vector<int> mergeInsertionSort(std::vector<int>& numbers) {

    int vecSize = numbers.size();

    if (vecSize <= 1)
        return numbers;

    bool isOdd = (vecSize % 2 == 1);
    int oddElement = -1;

    if (isOdd) {
        oddElement = numbers.back();
        vecSize--;
    }

    std::vector<std::pair<int, int> > pairs;
    for (int i = 0; i < n; i+=2) {
        if (numbers[i] <= numbers[i+1]) 
            pairs.push_back({numbers[i], numbers[i+1]});
        else
            pairs.push_back({numbers[i+1], numbers[i]});
    }

    std::vector<int> mainChain;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        mainChain.push_back(it->second);
    
    // mainChain = mergeInsertionSort(mainChain);
}
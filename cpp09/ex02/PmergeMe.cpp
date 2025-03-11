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

int jacobsthal(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<int> getJacobsthalOrder(int size) {
    std::vector<int> indices;
    
    std::vector<int> jacobNumbers;
    jacobNumbers.push_back(0);
    jacobNumbers.push_back(1);
    
    while (jacobNumbers.back() < size) {
        int next = jacobNumbers[jacobNumbers.size() - 1] + 2 * jacobNumbers[jacobNumbers.size() - 2];
        jacobNumbers.push_back(next);
    }
    
    for (size_t i = 2; i < jacobNumbers.size(); i++) {
        int current = jacobNumbers[i];
        int previous = jacobNumbers[i-1];
        
        for (int k = current; k > previous; k--) {
            if (k <= size) {
                indices.push_back(k);
            }
        }
    }

    for (int i = 1; i <= size; i++) {
        if (std::find(indices.begin(), indices.end(), i) == indices.end()) {
            indices.push_back(i);
        }
    }

    return indices;
}

std::vector<int> mergeInsertionSort(std::vector<int>& numbers) {

    int vecSize = numbers.size();

    if (vecSize <= 1)
        return numbers;

    bool isOdd = (vecSize % 2 == 1);
    int oddElement = -1;

    if (isOdd) {
        oddElement = numbers.back();
        numbers.pop_back();
        vecSize--;
    }

    std::vector<std::pair<int, int> > pairs;
    for (int i = 0; i < vecSize; i+=2) {
        if (i + 1 < vecSize) {
            if (numbers[i] <= numbers[i+1]) 
                pairs.push_back(std::make_pair(numbers[i], numbers[i+1]));
            else
                pairs.push_back(std::make_pair(numbers[i+1], numbers[i]));
        }
    }

    std::vector<int> mainChain;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        mainChain.push_back(it->second);
    
    mainChain = mergeInsertionSort(mainChain);

    std::vector<int> result;
    std::cout << "First pair: (" << pairs[0].first << "," << pairs[0].second << ")" << std::endl;
    result.push_back(pairs[0].first);

    for (std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
        result.push_back(*it);
    
    std::vector<int> pendElements;
    for (size_t i = 1; i < pairs.size(); i++)
        pendElements.push_back(pairs[i].first);
    
    std::vector<int> indexOrder = getJacobsthalOrder(pendElements.size());

    for (std::vector<int>::iterator it = indexOrder.begin(); it != indexOrder.end(); ++it) {
        int element = pendElements[(*it) - 1];
        
        int low = 0;
        int high = result.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (result[mid] < element)
                low = mid + 1;
            else
                high = mid;
        }

        result.insert(result.begin() + low, element);
    }

    if (isOdd) {
        int low = 0;
        int high = result.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (result[mid] < oddElement)
                low = mid + 1;
            else
                high = mid;
        }
        result.insert(result.begin() + low, oddElement);
    }
    return result;
}
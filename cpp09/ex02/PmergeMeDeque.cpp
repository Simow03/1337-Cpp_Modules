#include "PmergeMe.hpp"

double ELAPSED_DEQUE;

std::deque<int> getJacobsthalOrderDeque(int size) {
    std::deque<int> indices;
    
    std::deque<int> jacobNumbers;
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

std::deque<int> mergeInsertionSortDeque(std::deque<int>& numbers) {

    clock_t start = clock();
    int vecSize = numbers.size();

    if (vecSize <= 1)
        return numbers;

    bool isOdd = (vecSize % 2 == 1);
    int oddElement = -1;

    if (isOdd) {
        oddElement = numbers.back();
        vecSize--;
    }

    std::deque<std::pair<int, int> > pairs;
    for (int i = 0; i < vecSize; i+=2) {
            if (numbers[i] <= numbers[i+1]) 
                pairs.push_back(std::make_pair(numbers[i], numbers[i+1]));
            else
                pairs.push_back(std::make_pair(numbers[i+1], numbers[i]));
    }

    std::deque<int> mainChain;
    for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        mainChain.push_back(it->second);
    
    mainChain = mergeInsertionSortDeque(mainChain);

    std::deque<int> result;
    result.push_back(pairs[0].first);

    for (std::deque<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
        result.push_back(*it);
    
    std::deque<int> pendElements;
    for (size_t i = 1; i < pairs.size(); i++)
        pendElements.push_back(pairs[i].first);
    
    std::deque<int> indexOrder = getJacobsthalOrderDeque(pendElements.size());

    for (std::deque<int>::iterator it = indexOrder.begin(); it != indexOrder.end(); ++it) {
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

    clock_t end = clock();

    ELAPSED_DEQUE = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    return result;
}
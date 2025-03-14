#include "PmergeMe.hpp"

double ELAPSED_DEQUE;

std::deque<int> getJacobsthalOrderDeque(int size)
{
    std::deque<int> jacobsthalNumbers;
    std::deque<int> result;

    jacobsthalNumbers.push_back(0);
    jacobsthalNumbers.push_back(1);
    jacobsthalNumbers.push_back(3);

    int nextNumber = 0;

    for(int i = 3; i < size && nextNumber < size; i++) {
        nextNumber = jacobsthalNumbers[i - 1] + (2 * jacobsthalNumbers[i - 2]);
        jacobsthalNumbers.push_back(nextNumber);
    }
    
    int lastValue = 1;
    for(int i = 0; i < (int)jacobsthalNumbers.size(); i++) {

        if(jacobsthalNumbers[i] < size)
            result.push_back(jacobsthalNumbers[i]);

        int currentValue = jacobsthalNumbers[i] -1;
    
        while(currentValue > lastValue)
        {
            if(currentValue < size)
                result.push_back(currentValue);

            currentValue--;
        }

        lastValue = jacobsthalNumbers[i];
    }

    return result;
}

std::deque<std::pair<int,int> > mergeSortDeque(std::deque<std::pair<int,int> > pairs)
{
    std::deque<std::pair<int,int> > right;
    std::deque<std::pair<int,int> > left;
    std::deque<std::pair<int,int> > res;

    size_t i = 0;

    for(;i < pairs.size() / 2; i++)
        right.push_back(pairs[i]);

    for(;i < pairs.size(); i++)
        left.push_back(pairs[i]);

    if(left.size() > 1)
        left = mergeSortDeque(left);

    if(right.size() > 1)
        right = mergeSortDeque(right);

    int x = 0;
    int y = 0;

    while((x < (int)left.size())|| (y < (int)right.size())) {

        if(x == (int)left.size()) {
            res.push_back(std::make_pair(right[y].first, right[y].second));
            y++;
        }
        else if(y == (int)right.size()) {
            res.push_back(std::make_pair(left[x].first, left[x].second));
            x++;
        }
        else if(left[x].second <= right[y].second ) {
            res.push_back(std::make_pair(left[x].first, left[x].second));
            x++;
        }
        else {
            res.push_back(std::make_pair(right[y].first, right[y].second));
            y++;
        }
    }

    return res;
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

    
    pairs = mergeSortDeque(pairs);
    std::deque<int> mainChain;
    std::deque<int> pendElements;
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if(i == 0) {
            mainChain.push_back(pairs[i].first);
            mainChain.push_back(pairs[i].second);
            continue;
        }
        
        mainChain.push_back(pairs[i].second);
        pendElements.push_back(pairs[i].first);
    }
    
    std::deque<int> indexOrder = getJacobsthalOrderDeque(pendElements.size());

    int y = 0;
    for(int i = 0; y < (int)pendElements.size();i++) {
        if (indexOrder[i] >= (int)pendElements.size())
            continue;
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendElements[indexOrder[i]]);
        mainChain.insert(pos,pendElements[indexOrder[i]]);
        y++;
    }
    if(isOdd) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(pos, oddElement);
    }

    clock_t end = clock();

    ELAPSED_DEQUE = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    return mainChain;
}
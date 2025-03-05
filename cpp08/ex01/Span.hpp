#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostream>

class Span {
private:
    std::vector<int> vec;
    unsigned int N;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int number);
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        size_t remainingSpace = N - vec.size();
        size_t newElementCount = std::distance(begin, end);

        if (newElementCount > remainingSpace)
            throw std::runtime_error("Insufficient space to insert elements.");
    
        vec.insert(vec.end(), begin, end);
    };
    int shortestSpan(void) const;
    int longestSpan(void) const;
};

#endif
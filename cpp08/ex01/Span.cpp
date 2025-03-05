#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <exception>
#include <iterator>

Span::Span() : N(0) {}

Span::Span(unsigned int _N) : N(_N) {
    if (_N == 0)
        throw std::invalid_argument("Span size must be greater than zero!");
}

Span::Span(const Span& other) : vec(other.vec), N(other.N) {}

Span& Span::operator=(const Span& other){
    if (this != &other) {
        vec = other.vec;
        N = other.N;
    }

    return *this;
}

void Span::addNumber(int number) {
    if (vec.size() >= N)
        throw std::runtime_error("Span already full");
    
    vec.push_back(number);
}

int Span::shortestSpan() const{
    if (vec.size() < 2)
        throw std::logic_error("Not enough elements to calculate shortest span.");
    
    std::vector<int> sortedVec = vec;

    std::sort(sortedVec.begin(), sortedVec.end());
    int minSpan = std::numeric_limits<int>::max();

    for (size_t i = 1; i < sortedVec.size(); i++) {
        int diff = std::abs(sortedVec[i] - sortedVec[i-1]);
        minSpan = std::min(minSpan, diff);
    }

    return minSpan;
}

int Span::longestSpan() const {
    if (vec.size() < 2)
        throw std::logic_error("Not enough elements to calculate longest span.");
    
    int minElement = *std::min_element(vec.begin(), vec.end());
    int maxElement = *std::max_element(vec.begin(), vec.end());

    return std::abs(maxElement - minElement);
}

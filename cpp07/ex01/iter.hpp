#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <cctype>

template <typename T, typename F>
void iter(T* array, size_t len , F function) {
    if (!array)
        return ;

    for (size_t i = 0; i < len; i++) {
        function(array[i]);
    }
}

void doubleValue(int& x) {
    x *= 2;
}

void rot13(std::string& str) {
    if (str.empty())
        return;

    for (size_t i = 0; i < str.length(); i++) {
        if (isalpha(str[i] + 13))
            str[i] += 13;
    }
}

template <typename T>
void print(T const& value) {
    std::cout << value << ", "; 
}

#endif
#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstdlib>
#include <ctime>
#include <exception>

template <typename T>
class Array {
private :
    T* elements;
    unsigned int arrSize;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    ~Array();

    Array& operator=(const Array& other);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size(void) const;
};

#include "Array.tpp"

#endif
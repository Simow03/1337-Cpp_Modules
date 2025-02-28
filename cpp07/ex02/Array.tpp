#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T>
Array<T>::Array() : elements(NULL), arrSize(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : arrSize(n) {
    if (n > 0)
        elements = new T[n]();
    else
        elements = NULL;
};

template<typename T>
Array<T>::Array(const Array& other) : arrSize(other.arrSize){
    if (arrSize > 0) {
        elements = new T[arrSize];
        for (size_t i = 0; i < arrSize; i++)
            elements[i] = other.elements[i];
    }
    else
        elements = NULL;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        if (elements)
            delete[] elements;

        arrSize = other.arrSize;

        if (arrSize > 0) {
            elements = new T[arrSize];
            for (size_t i = 0; i < arrSize; i++)
                elements[i] = other.elements[i];
        }
        else
            elements = NULL;
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= arrSize)
        throw std::exception();
    return elements[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= arrSize)
        throw std::exception();
    return elements[index];
}

template<typename T>
Array<T>::~Array() {
    if (elements)
        delete[] elements;
}

template<typename T>
unsigned int Array<T>::size() const{
    return arrSize;
}

#endif
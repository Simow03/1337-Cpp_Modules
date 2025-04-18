#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:
    typedef typename Container::iterator iterator;

    MutantStack() : std::stack<T, Container>() {}

    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}

    MutantStack& operator=(const MutantStack& other) {
        if (this != &other)
            std::stack<T, Container>::operator=(other);
        
        return *this;
    }

    ~MutantStack() {}

    iterator begin() {
        return this->c.begin();
    }
    iterator end() {
        return this->c.end();
    }
};

#endif
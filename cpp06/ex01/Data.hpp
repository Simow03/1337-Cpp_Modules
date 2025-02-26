#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data
{
    int id;
    char initial;
    bool isHuman;

    Data(int id, char initial, bool isHuman);
};

#endif
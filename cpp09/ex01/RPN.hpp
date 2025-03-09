#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>


int countSegments(const std::string& str, char delimiter);
std::string* splitString(std::string fileContent, char delimiter);
void freeSplitString(std::string* array);
int calculateRPN(std::string input);
int runOperation(std::stack<int>& rpnStack, std::string* inputArray, size_t i);

#endif
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <stack>


int countSegments(const std::string& str, char delimiter);
std::string* splitString(std::string fileContent, char delimiter);
void freeSplitString(std::string* array);
float calculateRPN(std::string input);
void runOperation(std::stack<float>& rpnStack, std::string* inputArray, size_t i);

#endif
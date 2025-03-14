#include "RPN.hpp"

bool isoperation(const char& op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

void runOperation(std::stack<float>& rpnStack, std::string* inputArray, size_t i) {

    if (rpnStack.size() < 2) {
        std::cerr << "Error" << std::endl;
        freeSplitString(inputArray);
        exit(1);
    }

    float n2 = rpnStack.top();
    rpnStack.pop();
    float n1 = rpnStack.top();
    rpnStack.pop();

    char op = inputArray[i][0]; 

    switch (op)
    {
    case '+':
        rpnStack.push(n1 + n2);
        break;
    case '-':
        rpnStack.push(n1 - n2);
        break;
    case '*':
        rpnStack.push(n1 * n2);
        break;
    case '/':
        if (n2 == 0) {
            std::cerr << "Error" << std::endl;
            freeSplitString(inputArray);
            exit(1);
        }
        rpnStack.push(n1 / n2);
    default:
        break ;
    }
}

float calculateRPN(std::string input) {

    std::stack<float> rpnStack;

    std::string* inputArray = splitString(input, ' ');
    size_t count = atoi(inputArray[0].c_str());

    for (size_t i = 1; i <= count; i++) {
        if (inputArray[i].length() != 1) {
            std::cerr << "Error" << std::endl;
            freeSplitString(inputArray);
            exit(1);
        }

        char c = inputArray[i][0];
        if (isdigit(c))
            rpnStack.push(c - '0');

        else if (isoperation(c))
            runOperation(rpnStack, inputArray, i);

        else {
            std::cerr << "Error" << std::endl;
            freeSplitString(inputArray);
            exit(1);
        }
    }

    if (rpnStack.size() != 1) {
        std::cerr << "Error" << std::endl;
        freeSplitString(inputArray);
        exit(1);
    }

    freeSplitString(inputArray);

    return rpnStack.top();
}
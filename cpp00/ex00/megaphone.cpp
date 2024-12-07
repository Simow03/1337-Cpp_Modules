#include <iostream>

std::string toUpperStr(std::string s)
{
    for (int i = 0; i < (int)s.length(); i++)
        s[i] = toupper(s[i]);
    return s;
}

int main(int argc, char* argv[])
{
    if (argc >= 2)
    {
        for (int i = 1; i < argc; i++)
            std::cout << toUpperStr(argv[i]);
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
}

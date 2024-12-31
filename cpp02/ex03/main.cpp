#include "Point.hpp"

void pointInside() {
    std::cout << "Test case : inside" << std::endl;
    Point a(2, 5);
    Point b(1, 1);
    Point c(5, 1);
    Point point(3, 2);

    if (bsp(a, b, c, point) == true)
        std::cout << "Result : \033[32mTRUE\033[0m" << std::endl;
    else
        std::cout << "Result : \033[31mFALSE\033[0m" << std::endl;
}

void pointOutside() {
    std::cout << "Test case : outside" << std::endl;
    Point a(5, 7);
    Point b(8, 8);
    Point c(10, 2);
    Point point(2, 10);

    if (bsp(a, b, c, point) == true)
        std::cout << "Result : \033[32mTRUE\033[0m" << std::endl;
    else
        std::cout << "Result : \033[31mFALSE\033[0m" << std::endl;
}

void vertexPoint() {
    std::cout << "Test case : vertex" << std::endl;
    Point a(7, -10);
    Point b(1, 1);
    Point c(-7, -2);
    Point point(1, 1);

    if (bsp(a, b, c, point) == true)
        std::cout << "Result : \033[32mTRUE\033[0m" << std::endl;
    else
        std::cout << "Result : \033[31mFALSE\033[0m" << std::endl;
}

void onEdgePoint() {
    std::cout << "Test case : on edge" << std::endl;
    Point a(-1, 1);
    Point b(2, 1);
    Point c(-1, -1);
    Point point(-1, 0);

    if (bsp(a, b, c, point) == true)
        std::cout << "Result : \033[32mTRUE\033[0m" << std::endl;
    else
        std::cout << "Result : \033[31mFALSE\033[0m" << std::endl;
}


int main(void)
{
    pointInside();
    pointOutside();
    vertexPoint();
    onEdgePoint();
}

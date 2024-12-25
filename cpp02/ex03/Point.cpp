#include "Point.hpp"

Point::Point() : x(0), y(0) {};

Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal) {};

Point::Point(const Point &point)
{
    *this = point;
}

Fixed Point::getX()
{
    return x;
}

Fixed Point::getY()
{
    return y;
}

Point &Point::operator=(const Point &point)
{
    if (this != &point)
    {
        this->x = point.getX();
        this->y = point.getY();
    }
    return *this;
}

Point::~Point() {};
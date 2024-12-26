#include "Point.hpp"

Point::Point() : x(0), y(0) {};

Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal) {};

Point::Point(const Point &point) : x(point.getX()), y(point.getY()) {};

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}

Point &Point::operator=(const Point &point)
{
    (void)point;
    return *this;
}

Point::~Point() {};
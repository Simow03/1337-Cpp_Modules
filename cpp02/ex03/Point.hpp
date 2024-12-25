#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"
class Point {
private:
    Fixed const x;
    Fixed const y;

public:
    Point();
    Point(const float xVal, const float yVal);
    Point(const Point& point);
    Point& operator=(const Point& point);
    ~Point();
    Fixed getX(void);
    Fixed getY(void);
};

bool bsp(Point const a,  Point const b, Point const c, Point const point);

#endif
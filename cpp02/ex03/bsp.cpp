#include "Point.hpp"

Fixed areaCalculator(Point const i, Point const j, Point const k) {
    float value = ((i.getX().toFloat() * (j.getY().toFloat() - k.getY().toFloat()))
    + (j.getX().toFloat() * (k.getY().toFloat() - i.getY().toFloat()))
    + (k.getX().toFloat() * (i.getY().toFloat - j.getY().toFloat()))) / 2;

    return Fixed(value);
}

bool haveSameSign(float a, float b, float c) {
    return (a > 0 && b > 0 && c > 0) || (a < 0 && b < 0 && c < 0);
}

bool bsp(Point const a,  Point const b, Point const c, Point const point)
{
    Fixed abp = areaCalculator(a, b, point);
    Fixed acp = areaCalculator(a, c, point);
    Fixed bcp = areaCalculator(b, c, point);

    if (abp.toFloat() == 0 || acp.toFloat() == 0 || bcp.toFloat() == 0)
        return false;

    return (haveSameSign(abp.toFloat(), acp.toFloat(), bcp.toFloat()));
}
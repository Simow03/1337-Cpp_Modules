#include "Fixed.hpp"

Fixed::Fixed() : value(0) {};

Fixed::Fixed(const Fixed &other)
{
    *this = other;
};

Fixed::Fixed(const int newValue)
{
    value = newValue << fractionalBit;
}

Fixed::Fixed(const float newValue)
{
    value = roundf(newValue * (1 << fractionalBit));
}

Fixed::~Fixed() {
};

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
};

int Fixed::getRawBits(void) const
{
    return this->value;
};

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
};

float Fixed::toFloat() const
{
    return (float)value / (1 << fractionalBit);
}

int Fixed::toInt() const
{
    return value >> fractionalBit;
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->value > other.value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->value != other.value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed fixed;
    fixed.setRawBits(this->value + other.value);
    return fixed;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed fixed;
    fixed.setRawBits(this->value - other.value);
    return fixed;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed fixed;
    long long tmp = (long long)this->value * other.value;
    fixed.setRawBits(tmp >> fractionalBit);
    return fixed;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed fixed;
    if (other.value != 0)
    {
        long long tmp = ((long long)this->value << fractionalBit) / other.value;
        fixed.setRawBits(tmp);
    }
    return fixed;
}

Fixed &Fixed::operator++()
{
    this->value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed fixed(*this);
    ++(*this);
    return fixed;
}

Fixed &Fixed::operator--()
{
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed fixed(*this);
    --(*this);
    return fixed;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
    out << other.toFloat();
    return out;
}
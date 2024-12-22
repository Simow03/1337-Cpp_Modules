#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
};

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
};

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits( void ) const {
    return this->value;
};

void Fixed::setRawBits( int const raw ) {
    this->value = raw;
};

Fixed::Fixed(const int newValue ) {
    std::cout << "Int constructor called" << std::endl;
    value = newValue << fractionalBit;
}

Fixed::Fixed(const float newValue ) {
    std::cout << "Float constructor called" << std::endl;
    value = roundf(newValue * (1 << fractionalBit));
}


float Fixed::toFloat() const {
    return (float)value / (1 << fractionalBit);
}

int Fixed::toInt() const {
    return value >> fractionalBit;
}

std::ostream& operator<<(std::ostream& out, const Fixed& other){
    out << other.toFloat();
    return out;
}

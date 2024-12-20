#include "Fixed.hpp"

Fixed::Fixed() : value(0) {};
Fixed::Fixed(const Fixed& other) {};
Fixed& Fixed::operator=(Fixed& other) {};
Fixed::~Fixed() {};
int Fixed::getRawBits( void ) const {};
void Fixed::setRawBits( int const raw ) {};
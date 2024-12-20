#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
private:
    int value;
    const static int fractionalBit;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(Fixed& other);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif
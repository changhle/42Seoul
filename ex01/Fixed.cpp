#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
	std::cout << "Default constructor called" << '\n';
	fixed_point_value = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point_value = num << fractional_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point_value = roundf(num * 256);
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << '\n';
	fixed_point_value = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << '\n';
	fixed_point_value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << '\n';
}

void Fixed::setRawBits(int const raw)
{
	fixed_point_value = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point_value);
}
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	fixed_point_value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	fixed_point_value = raw;
}

int Fixed::getRawBits(void) const
{
	return (fixed_point_value);
}

float Fixed::toFloat(void) const
{
	return ((float)fixed_point_value / 256);
}

int Fixed::toInt(void) const
{
	return (fixed_point_value >> fractional_bits);
}

std::ostream& operator<<(std::ostream &os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

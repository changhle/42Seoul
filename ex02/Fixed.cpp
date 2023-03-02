#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
	fixed_point_value = 0;
}

Fixed::Fixed(const int num)
{
	fixed_point_value = num << fractional_bits;
}

Fixed::Fixed(const float num)
{
	fixed_point_value = roundf(num * 256);
}

Fixed::Fixed(const Fixed& fixed) {
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	fixed_point_value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
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

bool	Fixed::operator>(const Fixed& obj) const
{
	return (this->getRawBits() > obj.getRawBits());
}

bool	Fixed::operator<(const Fixed& obj) const
{
	return (this->getRawBits() < obj.getRawBits());
}

bool	Fixed::operator>=(const Fixed& obj) const
{
	return (this->getRawBits() >= obj.getRawBits());
}

bool	Fixed::operator<=(Fixed const& obj) const
{
	return (this->getRawBits() <= obj.getRawBits());
}

bool	Fixed::operator==(const Fixed& obj) const
{
	return (this->getRawBits() == obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed& obj) const
{
	return (this->getRawBits() != obj.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& obj) const
{
	return (this->toFloat() - obj.toFloat());
}

Fixed	Fixed::operator-(const Fixed& obj) const
{
	return (this->toFloat() - obj.toFloat());
}

Fixed	Fixed::operator*(const Fixed& obj) const
{
	return (this->toFloat() * obj.toFloat());
}

Fixed	Fixed::operator/(const Fixed& obj) const
{
	return (this->toFloat() / obj.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	++fixed_point_value;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed	tmp(*this);
	fixed_point_value++;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	--fixed_point_value;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed	tmp(*this);
	fixed_point_value--;
	return (*this);
}

Fixed&	Fixed::min(Fixed& ref1, Fixed& ref2)
{
	if (ref1 <= ref2)
		return (ref1);
	return (ref2);
}

const Fixed&	Fixed::min(const Fixed& ref1, const Fixed& ref2)
{
	if (ref1 <= ref2)
		return (ref1);
	return (ref2);
}

Fixed&	Fixed::max(Fixed& ref1, Fixed& ref2)
{
	if (ref1 <= ref2)
		return (ref2);
	return (ref1);
}

const Fixed&	Fixed::max(const Fixed& ref1, const Fixed& ref2)
{
	if (ref1 <= ref2)
		return (ref2);
	return (ref1);
}
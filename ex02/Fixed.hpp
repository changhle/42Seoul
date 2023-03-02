#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					fixed_point_value;
		static const int	fractional_bits = 8;

	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& obj);
		Fixed&	operator=(const Fixed& obj);
		~Fixed();
		void				setRawBits(int const raw);
		int					getRawBits(void) const;
		float				toFloat(void) const;
		int					toInt(void) const;

		bool				operator>(const Fixed& obj) const;
		bool				operator<(const Fixed& obj) const;
		bool				operator>=(const Fixed& obj) const;
		bool				operator<=(const Fixed& obj) const;
		bool				operator==(const Fixed& obj) const;
		bool				operator!=(const Fixed& obj) const;

		Fixed				operator+(const Fixed& obj) const;
		Fixed				operator-(const Fixed& obj) const;
		Fixed				operator*(const Fixed& obj) const;
		Fixed				operator/(const Fixed& obj) const;

		Fixed&				operator++(void);
		const Fixed			operator++(int);
		Fixed&				operator--(void);
		const Fixed			operator--(int);

		static Fixed&		min(Fixed& ref1, Fixed& ref2);
		static const Fixed&	min(const Fixed& ref1, const Fixed& ref2);
		static Fixed&		max(Fixed& ref1, Fixed& ref2);
		static const Fixed&	max(const Fixed& ref1, const Fixed& ref2);
};

std::ostream& operator<<(std::ostream &os, const Fixed& fixed);

#endif

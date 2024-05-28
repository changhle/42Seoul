#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
	private:
		T				*array;
		unsigned int	arraySize;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& obj);
		~Array();
		Array&			operator=(const Array& obj);
		T&				operator[](unsigned int index);
		const T&		operator[](unsigned int index) const;
		unsigned int	size() const;
		class IndexException : public std::exception {
			public:
				const char *what() const throw();
		};
};

#include "Array.tpp"

#endif

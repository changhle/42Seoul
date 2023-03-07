#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, std::size_t len, void (*func)(T &))
{
	for (std::size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void	print(T &arg)
{
	std::cout << arg << " ";
}

template <typename T>
void	pow(T &arg)
{
	arg = arg * arg;
}

#endif
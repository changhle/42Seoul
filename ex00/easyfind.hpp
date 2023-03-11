#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>

template <typename T>
typename T::iterator	easyfind(T container, int value)
{
	typename T::iterator	iter;
	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw std::range_error("There is no value");
	return (iter);
}

#endif

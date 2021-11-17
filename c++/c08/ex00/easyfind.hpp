#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

template <typename T>
typename T::const_iterator easyfind(T &cont, int toFind)
{
	typename T::const_iterator it = find(cont.begin(), cont.end(), toFind);
	if (it == cont.end())
		throw std::runtime_error("Can't find element");
	else
		return (it);
}
#endif
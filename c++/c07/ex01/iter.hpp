#ifndef ITER
#define ITER
#include <iostream>

template <typename T>
void iter(T ptr[], size_t lenght, void (*fn)(T &arg))
{
	for (size_t i = 0; i < lenght; i++)
	{
		fn(ptr[i]);
	}
}

template <typename T>
void list(T &element)
{
	std::cout << element << std::endl;
}

template <typename T>
void increment(T &element)
{
	element++;
}
#endif
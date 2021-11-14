#ifndef WHATEVER
#define WHATEVER

template <typename T>
void swap (T &a, T &b)
{
	T c;

	c = b;
	b = a;
	a = c;
}

template <typename T>
T min(T a, T b)
{
	return (a < b ? a : b);
}

template <typename T>
T max(T a, T b)
{
	return (a > b ? a : b);
}

#endif
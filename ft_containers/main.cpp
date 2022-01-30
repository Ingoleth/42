#include <vector>
#include <list>
#include <iostream>
#include "stack.hpp"
#include "vector.hpp"
#include "BinaryTree.hpp"
#include "utils.hpp"
#include "map.hpp"
#include <map>
#include "tests/tests.hpp"
#include <string>

#include <ctime>
#include <cstdlib>
#include <stdio.h>

void test_init_times()
{
	ft::map<long, int> mapa;
	std::map<long, int> mapa2;

	long seed = time(NULL);
	long size = 10;
	std::cout << "semilla: " << seed << std::endl;
	std::cout << "Tested size: " << size << std::endl;
	srand(seed);
	std::vector<long> values;
	values.reserve(size);
	for (unsigned int i = 0; i < size; ++i)
		values[i] = random();
	clock_t init_time = clock();
	for (unsigned int i = 0; i < size; ++i)
			mapa.insert(ft::map<long, int>::value_type(values[i], i));
	float execution_time = static_cast<float>(clock() - init_time)/(float)CLOCKS_PER_SEC;
    printf("Initialization time:     %f s\n", execution_time);

	float init_time2 = clock();
	for (unsigned int i = 0; i < size; ++i)
			mapa2.insert(std::map<long, int>::value_type(values[i], i));
	float execution_time2 = static_cast<float>(clock() - init_time2)/(float)CLOCKS_PER_SEC;
    printf("STL inizialization time: %f s\n", execution_time2);

	init_time = clock();
	for (ft::map<long, int>::iterator it = mapa.begin(); it != mapa.end(); it++) {}
	execution_time = static_cast<float>(clock() - init_time)/(float)CLOCKS_PER_SEC;
	printf("\nIteration time:          %f s\n", execution_time);

	init_time2 = clock();
	for (std::map<long, int>::iterator it = mapa2.begin(); it != mapa2.end(); it++) {}
	execution_time2 = static_cast<float>(clock() - init_time2)/(float)CLOCKS_PER_SEC;
	printf("STL iteration time:      %f s\n", execution_time2);

	return ;

	init_time = clock();
	for (long i = 0; i < (size / 2); i++)
		mapa.erase(values[i]);
	execution_time = static_cast<float>(clock() - init_time)/(float)CLOCKS_PER_SEC;
	printf("\nErasure time:            %f s\n", execution_time);

	init_time2 = clock();
	for (long i = 0; i < (size / 2); i++)
		mapa2.erase(values[i]);
	execution_time2 = static_cast<float>(clock() - init_time2)/(float)CLOCKS_PER_SEC;
	printf("STL erasure time:        %f s\n", execution_time2);

}

#define T1 char
#define T2 int
typedef ft::pair<const T1, T2> T3;

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int main()
{
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(lst_size - i + 'a', i));

	ft::map<T1, T2> mp(lst.begin(), lst.end());
	ft::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

	ft::map<T1, T2> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	ft::map<T1, T2> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);
	return 0;
}
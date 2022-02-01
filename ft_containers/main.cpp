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
	long size = 100000;
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

int main (void)
{
	test_vector();
	test_init_times();
	test_stack();
	test_map();
	return (0);
}
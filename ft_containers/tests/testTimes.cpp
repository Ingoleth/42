#include <vector>
#include "../vector.hpp"
#include <stack>
#include "../stack.hpp"
#include <map>
#include "../map.hpp"
#include "tests.hpp"

void test_vector_exec_times()
{
	ft::vector<long> ft_container;
	std::vector<long> stl_container;

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
			ft_container.push_back(ft::vector<long>::value_type(values[i]));
	float execution_time = static_cast<float>(clock() - init_time)/(float)CLOCKS_PER_SEC;
    printf("Initialization time:     %f s\n", execution_time);

	float init_time2 = clock();
	for (unsigned int i = 0; i < size; ++i)
			stl_container.push_back(std::vector<long>::value_type(values[i]));
	float execution_time2 = static_cast<float>(clock() - init_time2)/(float)CLOCKS_PER_SEC;
    printf("STL inizialization time: %f s\n", execution_time2);

	init_time = clock();
	for (ft::vector<long>::iterator it = ft_container.begin(); it != ft_container.end(); it++) {}
	execution_time = static_cast<float>(clock() - init_time)/(float)CLOCKS_PER_SEC;
	printf("\nIteration time:          %f s\n", execution_time);

	init_time2 = clock();
	for (std::vector<long>::iterator it = stl_container.begin(); it != stl_container.end(); it++) {}
	execution_time2 = static_cast<float>(clock() - init_time2)/(float)CLOCKS_PER_SEC;
	printf("STL iteration time:      %f s\n", execution_time2);

	init_time = clock();
	for (long i = size; i ; i--)
		ft_container.pop_back();
	execution_time = static_cast<float>(clock() - init_time)/(float)CLOCKS_PER_SEC;
	printf("\nErasure time:            %f s\n", execution_time);

	init_time2 = clock();
	for (long i = size; i ; i--)
		stl_container.pop_back();
	execution_time2 = static_cast<float>(clock() - init_time2)/(float)CLOCKS_PER_SEC;
	printf("STL erasure time:        %f s\n", execution_time2);

}

void test_stack_exec_times()
{
	ft::stack<long> ft_container;
	std::stack<long> stl_container;

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
			ft_container.push(values[i]);
	float execution_time = static_cast<float>(clock() - init_time)/(float)CLOCKS_PER_SEC;
    printf("Initialization time:     %f s\n", execution_time);

	float init_time2 = clock();
	for (unsigned int i = 0; i < size; ++i)
			stl_container.push(values[i]);
	float execution_time2 = static_cast<float>(clock() - init_time2)/(float)CLOCKS_PER_SEC;
    printf("STL inizialization time: %f s\n", execution_time2);

	init_time = clock();
	for (long i = size; i ; i--)
		ft_container.pop();
	execution_time = static_cast<float>(clock() - init_time)/(float)CLOCKS_PER_SEC;
	printf("\nErasure time:            %f s\n", execution_time);

	init_time2 = clock();
	for (long i = size; i ; i--)
		stl_container.pop();
	execution_time2 = static_cast<float>(clock() - init_time2)/(float)CLOCKS_PER_SEC;
	printf("STL erasure time:        %f s\n", execution_time2);

}

void test_map_exec_times()
{
	ft::map<long, int> ft_container;
	std::map<long, int> stl_container;

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
			ft_container.insert(ft::map<long, int>::value_type(values[i], i));
	float execution_time = static_cast<float>(clock() - init_time)/(float)CLOCKS_PER_SEC;
    printf("Initialization time:     %f s\n", execution_time);

	float init_time2 = clock();
	for (unsigned int i = 0; i < size; ++i)
			stl_container.insert(std::map<long, int>::value_type(values[i], i));
	float execution_time2 = static_cast<float>(clock() - init_time2)/(float)CLOCKS_PER_SEC;
    printf("STL inizialization time: %f s\n", execution_time2);

	init_time = clock();
	for (ft::map<long, int>::iterator it = ft_container.begin(); it != ft_container.end(); it++) {}
	execution_time = static_cast<float>(clock() - init_time)/(float)CLOCKS_PER_SEC;
	printf("\nIteration time:          %f s\n", execution_time);

	init_time2 = clock();
	for (std::map<long, int>::iterator it = stl_container.begin(); it != stl_container.end(); it++) {}
	execution_time2 = static_cast<float>(clock() - init_time2)/(float)CLOCKS_PER_SEC;
	printf("STL iteration time:      %f s\n", execution_time2);

	init_time = clock();
	for (long i = 0; i < (size / 2); i++)
		ft_container.erase(values[i]);
	execution_time = static_cast<float>(clock() - init_time)/(float)CLOCKS_PER_SEC;
	printf("\nErasure time:            %f s\n", execution_time);

	init_time2 = clock();
	for (long i = size; i ; i--)
		stl_container.erase(values[i]);
	execution_time2 = static_cast<float>(clock() - init_time2)/(float)CLOCKS_PER_SEC;
	printf("STL erasure time:        %f s\n", execution_time2);

}

void test_exec_time()
{
	print_header("VECTOR EXECUTION TIMES", true);
	test_vector_exec_times();
	print_header("STACK EXECUTION TIMES", true);
	test_stack_exec_times();
	print_header("MAP EXECUTION TIMES", true);
	test_map_exec_times();
}

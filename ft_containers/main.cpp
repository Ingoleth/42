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

int main (void)
{
	test_vector();
	test_stack();
	test_map();
	test_exec_time();
	test_leaks();
	return (0);
}
#include "serialize.hpp"
#include <iostream>

int main( void )
{
	Data data;
	uintptr_t raw;
	Data *data_ptr;

	data.value_1 = 17;
	data.value_2 = 42;

	raw = serialize(&data);
	data_ptr = deserialize(raw);
	std::cout << "Data values (from struct):\n" << data.value_1 << std::endl << data.value_2 << std::endl;
	std::cout << "Data values (from deserialized pointer):\n" << data_ptr->value_1 << std::endl << data_ptr->value_2 << std::endl;

	return 0;
}

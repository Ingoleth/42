#ifndef SERIALIZE
#define SERIALIZE
#include <stdint.h>
#include <string>


typedef struct t_data
{
	int value_1;
	int value_2;
}				Data;

uintptr_t	serialize(Data *ptr);
Data		*deserialize(uintptr_t raw);
#endif
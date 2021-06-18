
#include "push_swap.h"

int	find_smallest_num_a(t_array_info *arrays)
{
	int num;
	int i;
	int lenght;

	i = 0;
	lenght = arrays->array_a_length - arrays->sorted_elements_a;
	num = arrays->array_a[0];
	while (i < lenght)
	{
		if (arrays->array_a[i] < num)
			num = arrays->array_a[i];
		i++;
	}
	return (num);
}

int	find_biggest_num_b(t_array_info *arrays, int start, int end)
{
	int bigger_num;

	bigger_num = arrays->array_b[start];
	while (start < end)
	{
		if (arrays->array_b[start] > bigger_num)
			bigger_num = arrays->array_b[start];
		start++;
	}
	return (bigger_num);
}

t_bool	can_sort_a(t_array_info *arrays, int
	current_set_size, int i)
{
	int	bigest_number_b;
	int	bigest_number_b_tail;
	int	smallest_number_a;

	smallest_number_a = find_smallest_num_a(arrays);
	bigest_number_b = find_biggest_num_b(arrays, 0, current_set_size);
	bigest_number_b_tail = find_biggest_num_b(arrays, arrays->array_b_length - i - 1,
		arrays->array_b_length);
	if (bigest_number_b_tail > bigest_number_b)
		bigest_number_b = bigest_number_b_tail;
	if (bigest_number_b < smallest_number_a)
		return(true);
	else
		return (false);
}
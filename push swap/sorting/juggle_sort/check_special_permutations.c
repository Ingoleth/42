#include "push_swap.h"

t_bool	check_sortedness(t_array_info *arrays, int *current_set_size, int *i, int *j)
{
	int biggest_num;

	biggest_num = find_biggest_num_b(arrays, 0, arrays->array_b_length);
	i++;
	/*if (biggest_num == arrays->array_b[arrays->array_b_length - 1])
	{
		*i -= 1;
		*j += 1;
		instruction(rev_rot_a, arrays);
	}
	i++;
	if (biggest_num == arrays->array_b[1] && *j > 1)
	{
		instruction(swap_b, arrays);
		printf("Swappy swap\n");
	}*/
	if (biggest_num == arrays->array_b[0])
	{
		printf("I've done a swap!\n");
		*j -= 1;
		*current_set_size -= 1;
		instruction(push_a, arrays);
	}
	else
		return (false);
	return (true);
}

t_bool	check_special_permutations(t_array_info *arrays, int *current_set_size, int *i, int *j)
{
	t_bool done;

	done = 0;
	if (can_sort_a(arrays, *current_set_size, *i))
	{
		juggle_sort_a(arrays);
		while (*current_set_size && check_sortedness(arrays, current_set_size, i, j))
			done = true;
	}
	return (done);
}
#include "push_swap.h"

int	initialize_arrays_profiling(t_array_info *arrays, int lenght)
{
	int	seed;

	seed = rand();
	ft_memset(arrays, 0, sizeof(t_array_info));
	get_rand_array(lenght, seed, arrays);
	arrays->array_b = ft_calloc(arrays->array_a_length + 1, sizeof(int));
	arrays->profiling = true;
	if (arrays->array_b == NULL)
	{
		free(arrays->array_a);
		exit (1);
	}
	return (seed);
}

int	sorting_run(int array_lenght)
{
	t_array_info	arrays;
	int				seed;

	seed = initialize_arrays_profiling(&arrays, array_lenght);
	if (!is_sorted(arrays.array_a, arrays.array_a_length, ascending))
	{	
		if (arrays.array_a_length <= 3)
			sort_3(&arrays);
		else if (arrays.array_a_length <= 5)
			sort_5(&arrays);
		else
			juggle_sort_a(&arrays);
	}
	if (!is_sorted(arrays.array_a, arrays.array_a_length, ascending)
		|| arrays.array_b[0])
	{
		printf("Error on stack sorting run; Seed = %i\n", seed);
		free(arrays.array_a);
		free(arrays.array_b);
		exit(-1);
	}
	free(arrays.array_a);
	free(arrays.array_b);
	return (arrays.instruction_counter);
}

void	profile(char **argv, int argv_pos)
{
	int				array_lenght;
	int				number_checks;
	long int		mean;
	int				aux;

	array_lenght = ft_atoi(argv[argv_pos++]);
	if (!array_lenght || !argv[argv_pos])
	{
		printf("Error\n");
		exit(1);
	}
	number_checks = ft_atoi(argv[argv_pos++]);
	if (!array_lenght || argv[argv_pos])
	{
		printf("Error\n");
		exit(1);
	}
	mean = 0;
	aux = number_checks;
	while (aux--)
		mean += sorting_run(array_lenght);
	printf("Sorted in a mean of %li instructions;\n", mean / number_checks);
	exit (0);
}

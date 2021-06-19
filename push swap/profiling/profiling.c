#include "push_swap.h"

void    initialize_arrays_profiling(t_array_info *arrays, int lenght)
{
    int seed;

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
}

void    profile(char **argv, int argv_pos)
{
    int             array_lenght;
    int             number_checks;
    t_array_info    arrays;
    long int        mean;
    int             aux;
    int             max_operations;

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
        max_operations = 0;
        while (aux--)
        {
            initialize_arrays_profiling(&arrays, array_lenght);
            if (!is_sorted(arrays.array_a, arrays.array_a_length, ascending))
            {	
                if (arrays.array_a_length <= 3)
                    sort_3(&arrays);
                else if (arrays.array_a_length <= 5)
                    sort_5(&arrays);
                else
                    juggle_sort_a(&arrays);
            }
            free(arrays.array_a);
            free(arrays.array_b);
            if (arrays.instruction_counter > max_operations)
                max_operations = arrays.instruction_counter;
            mean += arrays.instruction_counter;
        }
        printf("Sorted in a mean of %li instructions;\nMax number of instructions: %i\n", mean / number_checks, max_operations);
        exit (0);
}
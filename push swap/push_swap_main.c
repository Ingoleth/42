/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:23:42 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/27 19:39:20 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_fd(t_bool file_output)
{
	int	fd;

	if (!file_output)
		return (STDOUT_FILENO);
	fd = open("instructions_list", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		return (STDOUT_FILENO);
	return (fd);
}

static void	print_results(t_array_info *arrays)
{
	t_list *aux;

	aux = arrays->instructions_list;
	while (aux)
	{
		ft_putstr_fd(aux->content, arrays->fd);
		aux = aux->next;
	}
	ft_lstclear(&arrays->instructions_list, free);
	print_stacks(arrays);
	if (is_sorted(arrays->array_a, arrays->array_a_length, ascending))
		printf("Array is sorted!\n");
	else
		printf("Array is not sorted!\n");
	//print_stacks(arrays);
	printf("Sorted in %i instructions!\n", arrays->instruction_counter);
}

int	main(int argc, char **argv)
{
	t_array_info	arrays;
	t_flags			flags;

	if (argc == 1)
		return (0);
	initialize_arrays(argc, argv, &arrays, &flags);
	arrays.fd = get_fd(flags.file_output);
	arrays.verbose = flags.verbose;
	if (flags.verbose)
		print_stacks(&arrays);
	if (!is_sorted(arrays.array_a, arrays.array_a_length, ascending))
	{	
		if (arrays.array_a_length <= 3)
			sort_3(&arrays);
		else if (arrays.array_a_length <= 5)
			sort_5(&arrays);
		else
			juggle_sort_a(&arrays);
	}
	if (flags.verbose)
		print_results(&arrays);
	free(arrays.array_a);
	free(arrays.array_b);
	if (arrays.fd)
		close(arrays.fd);
}

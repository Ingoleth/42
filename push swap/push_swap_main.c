/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:23:42 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 21:11:10 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** TODO: Check flag to print on a fd;
*/

int	main(int argc, char **argv)
{
	t_array_info	arrays;
	t_flags			flags;

	if (argc == 1)
		return (0);
	initialize_arrays(argc, argv, &arrays, &flags);
	print_stacks(&arrays);
	printf("\n");
	if (arrays.array_a_length <= 3)
		sort_3(&arrays, STDOUT_FILENO);
	else
		printf("Array too long!\n");
	printf("\n");
	print_stacks(&arrays);
	free(arrays.array_a);
	free(arrays.array_b);
}

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
	bubble_sort(&arrays, STDOUT_FILENO);
	free(arrays.array_a);
	free(arrays.array_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_arrays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:29:09 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/01 19:49:42 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_arrays(int argc, char **argv, t_array_info *arrays, t_flags
	*flags)
{
	ft_memset(arrays, 0, sizeof(t_array_info));
	handle_input(argc, argv, flags, arrays);
	arrays->array_b = ft_calloc(arrays->array_a_length + 1, sizeof(int));
	if (arrays->array_b == NULL)
	{
		free(arrays->array_a);
		exit (1);
	}
	arrays->max_array_length = arrays->array_a_length;
	arrays->instruction_counter = 0;
}

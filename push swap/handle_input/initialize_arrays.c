/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_arrays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:29:09 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 11:03:34 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flags	initialize_arrays(int argc, char **argv, int **array_a, int **array_b)
{
	int		length;
	t_flags	flags;

	*array_a = handle_input(argc, argv, &flags);
	length = get_array_length(*array_a);
	*array_b = ft_calloc(length + 1, sizeof(int));
	if (*array_b == NULL)
	{
		free(*array_a);
		exit (1);
	}
	return (flags);
}

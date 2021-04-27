/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:52:33 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/27 19:32:38 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(t_array_info *arrays)
{
	int	i;

	printf("Array = ");
	if (arrays->current_index == 0)
	{
		i = 0;
		while (i < arrays->array_a_length)
			printf("%d ", arrays->array_a[i++]);
	}
	else
	{
		i = arrays->array_a_length - arrays->current_index;
		while (i < arrays->array_a_length)
			printf("%d ", arrays->array_a[i++]);
		i = 0;
		while (i <= arrays->array_a_length - arrays->current_index - 1)
			printf("%d ", arrays->array_a[i++]);
	}
	printf("\n");
}

void	print_stacks(t_array_info *arrays)
{
	int	i;

	i = 0;
	while (i < arrays->array_a_length || i < arrays->array_b_length)
	{
		printf("(%3d) ", i);
		if (i < arrays->array_a_length)
			printf("[%7d]", arrays->array_a[i]);
		else if (arrays->array_b_length)
			printf("[       ]");
		if (i < arrays->array_b_length)
			printf(" [%7d]", arrays->array_b[i]);
		else if (i < arrays->array_a_length)
			printf(" [       ]");
		printf("\n");
		i++;
	}
	printf("          a         b\n\n");
	printf("A size = %i; B size = %i;\n\n", arrays->array_a_length,
		arrays->array_b_length);
}

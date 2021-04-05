/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:52:33 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 20:44:33 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_array_info *arrays)
{
	int	i;

	i = 0;
	while (i < arrays->array_a_length || i < arrays->array_b_length)
	{
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
	printf("    a         b\n\n");
	printf("A size = %i; B size = %i;\n\n", arrays->array_a_length,
		arrays->array_b_length);
	printf("Current index = %i\n", arrays->current_index);
}

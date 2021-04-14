/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_smaller_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:04:22 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/13 20:11:53 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_smaller_numbers(t_array_info *arrays,	t_list *small_numbers,
	int direction)
{
	int	i;

	i = 0;
	while (small_numbers)
	{
		while (arrays->array_a[0] != ((int *)small_numbers->content)[1])
		{
			printf("Current value = %i; Target value = %i;\n",
				arrays->array_a[0], (((int *)small_numbers->content)[1]));
			if (direction == right)
			{
				i++;
				instruction(rot_a, arrays);
			}
			else
			{
				i--;
				instruction(rev_rot_a, arrays);
			}
		}
		print_stacks(arrays);
		instruction(push_b, arrays);
		instruction(rot_b, arrays);
		small_numbers = small_numbers->next;
	}
}

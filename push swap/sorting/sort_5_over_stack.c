/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_over_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:48:00 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/04 18:01:40 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_over_stack(t_array_info *arrays, int stack)
{
	int	i;

	i = 2;
	if (stack == array_a)
	{
		if (!is_sorted(arrays->array_a, arrays->array_a_length, ascending))
		{
			while (i--)
				push_num(arrays, array_b, smaller);
			sort_3_over_stack(arrays, array_a);
			instruction(push_a, arrays);
			instruction(push_a, arrays);
		}
	}
	else
	{
		while (i--)
			push_num(arrays, array_a, bigger);
		sort_3_over_stack(arrays, array_b);
		instruction(push_b, arrays);
		instruction(push_b, arrays);
	}
}

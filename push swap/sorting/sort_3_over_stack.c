/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_over_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:48:00 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/04 18:02:42 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_b(t_array_info *arrays)
{
	int	length;

	length = 3;
	while (!is_sorted(arrays->array_b, length, descending) || length == 2)
	{
		if (arrays->array_b[0] < arrays->array_b[1])
			instruction(swap_b, arrays);
		else if (length == 3)
		{
			instruction(push_a, arrays);
			length--;
		}
		else
		{
			instruction(push_b, arrays);
			length++;
		}
	}
}

void	sort_to_a(t_array_info *arrays)
{
	int	length;

	length = 3;
	while (!is_sorted(arrays->array_a, length, ascending) || length == 2)
	{
		if (arrays->array_a[0] > arrays->array_a[1])
			instruction(swap_a, arrays);
		else if (length == 3)
		{
			instruction(push_b, arrays);
			length--;
		}
		else
		{
			instruction(push_a, arrays);
			length++;
		}
	}
}

void	sort_3_over_stack(t_array_info *arrays, int stack)
{
	if ((stack == array_a && arrays->array_a_length == 1)
		|| ((stack == array_b && arrays->array_b_length == 1)))
		return ;
	if ((stack == array_a && arrays->array_a_length == 2)
		|| (stack == array_b && arrays->array_b_length == 2))
	{
		if (stack == array_a
			&& !is_sorted(arrays->array_a, arrays->array_a_length, ascending))
			instruction(swap_a, arrays);
		else if (stack == array_b
			&& !is_sorted(arrays->array_b, arrays->array_b_length, descending))
			instruction(swap_b, arrays);
		return ;
	}
	if (stack == array_a)
		sort_to_a(arrays);
	else
		sort_to_b(arrays);
}

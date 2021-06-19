/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_over_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 23:24:23 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/27 11:06:13 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_b(t_array_info *arrays, int length)
{
	if (is_sorted(arrays->array_b, length, descending) || length < 2)
		return ;
	if (length == 2 || (arrays->array_b[0] < arrays->array_b[1]))
	{
		instruction (swap_b, arrays);
		if (length == 2 || is_sorted(arrays->array_b, length, descending))
			return ;
	}
	instruction(rot_b, arrays);
	instruction(swap_b, arrays);
	instruction(rev_rot_b, arrays);
	if (arrays->array_b[0] < arrays->array_b[1])
		instruction(swap_b, arrays);
}

void	sort_3_a(t_array_info *arrays, int length)
{
	if (is_sorted(arrays->array_a, length, ascending) || length < 2)
		return ;
/*	if (length == 2 || (arrays->array_a[0] > arrays->array_a[1]))
	{
		instruction (swap_a, arrays);
		if (length == 2 || is_sorted(arrays->array_a, length, ascending))
			return ;
	}
	instruction(rot_a, arrays);
	instruction(swap_a, arrays);
	instruction(rev_rot_a, arrays);
	if (arrays->array_a[0] > arrays->array_a[1])
		instruction(swap_a, arrays);*/
	if (length == 2)
	{
		instruction (swap_a, arrays);
			return ;
	}
	if (arrays->array_a[0] < arrays->array_a[2] && arrays->array_a[2] < arrays->array_a[1])
	{
		instruction(rot_a, arrays);
		instruction(swap_a, arrays);
		instruction(rev_rot_a, arrays);

	}
	else if (arrays->array_a[1] < arrays->array_a[0] && arrays->array_a[0] < arrays->array_a[2])
	{
		instruction(swap_a, arrays);
	}
	else if (arrays->array_a[2] < arrays->array_a[0] && arrays->array_a[0] < arrays->array_a[1])
	{
		instruction(rot_a, arrays);
		instruction(swap_a, arrays);
		instruction(rev_rot_a, arrays);
		instruction(swap_a, arrays);
	}
	else if (arrays->array_a[1] < arrays->array_a[2] && arrays->array_a[2] < arrays->array_a[0])
	{
		instruction(swap_a, arrays);
		instruction(rot_a, arrays);
		instruction(swap_a, arrays);
		instruction(rev_rot_a, arrays);
	}
	else if (arrays->array_a[2] < arrays->array_a[1] && arrays->array_a[1] < arrays->array_a[0])
	{
		instruction(swap_a, arrays);
		instruction(rot_a, arrays);
		instruction(swap_a, arrays);
		instruction(rev_rot_a, arrays);
		instruction(swap_a, arrays);
	}
}

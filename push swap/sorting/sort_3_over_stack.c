/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:48:00 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/01 21:23:08 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_array_info *arrays, int fd)
{
	int length;

	length = 3;
	if (arrays->array_a_length == 1)
		return ;
	if (arrays->array_a_length == 2)
	{
		if (!is_sorted(arrays->array_a, arrays->array_a_length))
			instruction(swap_a, fd, arrays);
		return ;
	}
	while (!is_sorted(arrays->array_a, 3))
	{
		if (arrays->array_a[0] > arrays->array_a[1])
			instruction(swap_a, fd, arrays);
		else if (length == 3)
		{
			instruction(push_b, fd, arrays);
			length--;
		}
		else
		{
			instruction(push_a, fd, arrays);
			length++;
		}
	}
}
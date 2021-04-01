/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:41:19 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 21:20:36 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_array_info *arrays, int fd)
{
	while (true)
	{
		if (arrays->array_a_length <= 1
			|| is_sorted(arrays->array_a, arrays->array_a_length))
			break ;
		if (arrays->array_a[0] > arrays->array_a[1])
			instruction(swap_a, fd, arrays);
		else
			instruction(rev_rot_a, fd, arrays);
		print_stacks(arrays);
	}
}

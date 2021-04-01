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
	while (!is_sorted(arrays->array_a, arrays->array_a_length))
	{
		if (arrays->array_a[0] > arrays->array_a[1])
			instruction(swap_a, fd, arrays);
		if (arrays->array_a[0] > arrays->array_a[2])
			instruction(rev_rot_a, fd, arrays);
		else
			instruction(rev_rot_a, fd, arrays);
	}
}

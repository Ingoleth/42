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

static unsigned int	find_smaller_number(int *array, unsigned int length)
{
	unsigned int	i;
	unsigned int	j;
	int				nb;

	i = 0;
	j = 0;
	nb = array[0];
	while (i < length)
	{
		if (array[i] < nb)
		{
			nb = array[i];
			j = i;
		}
		i++;
	}
	return (j);
}

void	push_first_two_nums(t_array_info *arrays, int fd)
{
	int	index;

	while (arrays->array_a_length != 3)
	{
		index = find_smaller_number(arrays->array_a, arrays->array_a_length);
		if (index <= arrays->array_a_length / 2)
		{
			while (index--)
				instruction(rot_a, fd, arrays);
			instruction(push_b, fd, arrays);
		}
		else
		{
			while (index++ < arrays->array_a_length)
				instruction(rev_rot_a, fd, arrays);
			instruction(push_b, fd, arrays);
		}
	}
}

void	sort_5(t_array_info *arrays, int fd)
{
	push_first_two_nums(arrays, fd);
	sort_3(arrays, fd);
	instruction(push_a, fd, arrays);
	instruction(push_a, fd, arrays);
}

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

static unsigned int	find_number(int *array, unsigned int length, int type)
{
	unsigned int	i;
	unsigned int	j;
	int				nb;

	i = 0;
	j = 0;
	nb = array[0];
	while (i < length)
	{
		if ((type == bigger && array[i] > nb)
            || (type == smaller && array[i] < nb))
		{
			nb = array[i];
			j = i;
		}
		i++;
	}
	return (j);
}

void    push_num_b(t_array_info *arrays, int fd, int type)
{
	int	index;

    index = find_number(arrays->array_a, arrays->array_a_length, type);
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

void    push_num_a(t_array_info *arrays, int fd, int type)
{
	int	index;

    index = find_number(arrays->array_b, arrays->array_b_length, type);
    if (index <= arrays->array_b_length / 2)
    {
        while (index--)
            instruction(rot_b, fd, arrays);
        instruction(push_a, fd, arrays);
    }
    else
    {
        while (index++ < arrays->array_b_length)
            instruction(rev_rot_b, fd, arrays);
        instruction(push_a, fd, arrays);
    }
}

void	push_num(t_array_info *arrays, int fd, int stack, int type)
{
    if (stack == array_a)
        push_num_a(arrays, fd, type);
    else
        push_num_b(arrays, fd, type);
}
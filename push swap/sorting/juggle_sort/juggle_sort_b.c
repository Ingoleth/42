/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juggle_sort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:12:57 by aiglesia          #+#    #+#             */
/*   Updated: 2021/06/18 20:52:09 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_and_rotate_forwards(t_array_info *arrays, int
	*current_set_size, int i)
{
	int	pivot;
	int	j;

	pivot = get_pivot(arrays->array_b, 0, *current_set_size);
	j = *current_set_size;
	while (j)
	{
		if (!check_special_permutations(arrays, current_set_size, &i, &j))
		{
			if (arrays->array_b[0] >= pivot)
			{
				instruction(push_a, arrays);
				*current_set_size -= 1;
			}
			else
			{
				instruction(rot_b, arrays);
				i++;
			}
			j--;
		}
	}
	return (i);
}

static int	push_and_rotate_backwards(t_array_info *arrays, int
	*current_set_size, int i)
{
	int	pivot;

	pivot = get_pivot(arrays->array_b, arrays->array_b_length
			- *current_set_size, arrays->array_b_length);
	while (i)
	{
		instruction(rev_rot_b, arrays);
		i--;
		if (arrays->array_b[0] >= pivot)
		{
			instruction(push_a, arrays);
			*current_set_size -= 1;
			if (can_sort_a(arrays, *current_set_size, i))
				juggle_sort_a(arrays);
		}
	}
	return (i);
}

t_list	*get_next_subdivision(t_list *subdivisions)
{
	t_list		*aux;

	aux = subdivisions;
	subdivisions = subdivisions->next;
	ft_lstdelone(aux, 0);
	return (subdivisions);
}

void	juggle_sort_b(t_array_info *arrays, t_list *subdivisions)
{
	int			i;
	int			current_set_size;

	while (subdivisions)
	{
		current_set_size = (int)((long int)subdivisions->content);
		i = 0;
		while (current_set_size)
		{
			if (i == 0)
				i = push_and_rotate_forwards(arrays, &current_set_size, i);
			else
				i = push_and_rotate_backwards(arrays, &current_set_size, i);
			juggle_sort_a(arrays);
		}
		subdivisions = get_next_subdivision(subdivisions);
	}
}

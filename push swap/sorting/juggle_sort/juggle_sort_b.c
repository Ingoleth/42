/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juggle_sort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:12:57 by aiglesia          #+#    #+#             */
/*   Updated: 2021/06/21 13:58:33 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	shorter_through_unordered(t_array_info *arrays, int i)
{
	if (i > arrays->array_b_length - i)
	{
		while (i++ < arrays->array_b_length)
			instruction(rot_b, arrays);
		return (true);
	}
	return (false);
}

static int	push_and_rotate_forwards(t_array_info *arrays, int
	*current_set_size, int i)
{
	int	pivot;
	int	j;

	pivot = get_pivot(arrays->array_b, 0, *current_set_size);
	j = *current_set_size;
	while (j > 0)
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
	int	j;

	j = 0;
	pivot = get_pivot(arrays->array_b, arrays->array_b_length
			- *current_set_size, arrays->array_b_length);
	if (shorter_through_unordered(arrays, i))
		return (0);
	while (i > 0)
	{
		instruction(rev_rot_b, arrays);
		i--;
		j++;
		if (!check_special_permutations(arrays, current_set_size, &i, &j))
		{
			if (arrays->array_b[0] >= pivot)
			{
				instruction(push_a, arrays);
				j--;
				*current_set_size -= 1;
			}
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

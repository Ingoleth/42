/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juggle_sort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:12:57 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/27 19:32:03 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool number_to_push(int *array, int lenght, int pivot)
{
	int i;

	i = 0;
	while (i < lenght)
	{
		if (array[i++] >= pivot)
			return (true);
	}
	return (false);
}

static int	push_and_rotate_forwards(t_array_info *arrays, long int
	*current_set_size, int i)
{
	int	pivot;

	pivot = get_pivot(arrays->array_b, 0, *current_set_size);
	while (number_to_push(arrays->array_b, *current_set_size, pivot))
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
	}
	return (i);
}

static int	push_and_rotate_backwards(t_array_info *arrays, long int
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
	long int	current_set_size;

	while (subdivisions)
	{
		current_set_size = (long int)subdivisions->content;
		i = 0;
		while (current_set_size > 3)
		{
			if (i == 0)
				i = push_and_rotate_forwards(arrays, &current_set_size, i);
			else
				i = push_and_rotate_backwards(arrays, &current_set_size, i);
		}
		while (i--)
			instruction(rev_rot_b, arrays);
		juggle_sort_a(arrays);
		sort_3_b(arrays, current_set_size);
		arrays->sorted_elements_a += current_set_size;
		while (current_set_size--)
			instruction(push_a, arrays);
		subdivisions = get_next_subdivision(subdivisions);
	}
}

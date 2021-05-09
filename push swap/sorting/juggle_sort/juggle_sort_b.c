/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juggle_sort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:12:57 by aiglesia          #+#    #+#             */
/*   Updated: 2021/05/09 16:52:15 by aiglesia         ###   ########.fr       */
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

static int	push_and_rotate_forwards(t_array_info *arrays, int
	*current_set_size, int i)
{
	int	pivot;
	int j;

	pivot = get_pivot(arrays->array_b, 0, *current_set_size);
	number_to_push(0, 0, 0);
	j = *current_set_size;
	//while (number_to_push(arrays->array_b, *current_set_size + 1, pivot))
	while (j)
	{
		if (arrays->array_b[0] >= pivot)
		{
			instruction(push_a, arrays);
			*current_set_size -= 1;
			arrays->elements_to_sort_b--;
		}
		else
		{
			instruction(rot_b, arrays);
			i++;
			arrays->elements_to_sort_b_inverted++;
		}
		j--;
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
		if (arrays->elements_to_sort_b)
			arrays->elements_to_sort_b_inverted--;
		i--;
		if (arrays->array_b[0] >= pivot)
		{
			arrays->elements_to_sort_b--;
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
	int			current_set_size;

	while (subdivisions)
	{
		current_set_size = (int)((long int)subdivisions->content);
		arrays->elements_to_sort_b = current_set_size;
		i = 0;
		while (current_set_size > 3 || i)
		{
			if (i == 0)
				i = push_and_rotate_forwards(arrays, &current_set_size, i);
			else
				i = push_and_rotate_backwards(arrays, &current_set_size, i);
			juggle_sort_a(arrays);
		}
		juggle_sort_a(arrays);
		sort_3_b(arrays, current_set_size);
		arrays->elements_to_sort_b = 0;
		arrays->sorted_elements_a += current_set_size;
		while (current_set_size--)
			instruction(push_a, arrays);
		subdivisions = get_next_subdivision(subdivisions);
	}
}

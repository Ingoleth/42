/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juggle_sort_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:13:13 by aiglesia          #+#    #+#             */
/*   Updated: 2021/05/09 17:07:47 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_and_rotate_backwards(t_array_info *arrays, unsigned long int
	*nb_swaps, int i)
{
	int	pivot;

	pivot = get_pivot(arrays->array_a, arrays->sorted_elements_a,
			arrays->array_a_length);
	if (i > arrays->sorted_elements_a)
	{
		while (i++ < arrays->array_a_length)
			instruction(rot_a, arrays);
		i = 0;
	}
	while (i)
	{
		instruction(rev_rot_a, arrays);
		arrays->array_a_offset--;
		i--;
		if (arrays->array_a[0] <= pivot)
		{
			instruction(push_b, arrays);
			*nb_swaps += 1;
		}
	}
	return (i);
}

static int	push_and_rotate_forwards(t_array_info *arrays,
	unsigned long int *nb_swaps, int i)
{
	int	pivot;

	pivot = get_pivot(arrays->array_a, 0, arrays->array_a_length
			- arrays->sorted_elements_a);
	while (i < arrays->array_a_length - arrays->sorted_elements_a)
	{
		if (arrays->array_a[0] <= pivot)
		{
			instruction(push_b, arrays);
			*nb_swaps += 1;
		}
		else
		{
			arrays->array_a_offset++;
			instruction(rot_a, arrays);
			i++;
		}
	}
	return (i);
}

void	juggle_sort_a(t_array_info *arrays)
{
	int					i;
	unsigned long int	nb_swaps;
	t_list				*subdivisions;

	i = 0;
	subdivisions = NULL;
	while (arrays->array_a_length > arrays->sorted_elements_a + 3 || i)
	{
		nb_swaps = 0;
		if (i == 0)
			i = push_and_rotate_forwards(arrays, &nb_swaps, i);
		else
			i = push_and_rotate_backwards(arrays, &nb_swaps, i);
		if (nb_swaps)
			ft_lstadd_front(&subdivisions, ft_lstnew((void *)nb_swaps));
	}
	sort_3_a(arrays, arrays->array_a_length - arrays->sorted_elements_a);
	arrays->sorted_elements_a += arrays->array_a_length
		- arrays->sorted_elements_a;
	juggle_sort_b(arrays, subdivisions);
}

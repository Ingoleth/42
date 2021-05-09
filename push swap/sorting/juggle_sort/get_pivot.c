/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:13:05 by aiglesia          #+#    #+#             */
/*   Updated: 2021/05/09 16:45:35 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(int *array, int start, int end)
{
	int	swaps;
	int	index;
	int	pivot;
	int	mean_num_of_swaps;
	int	i;

	index = start;
	mean_num_of_swaps = ((end - start) / 2);
	swaps = 0;
	while (swaps != mean_num_of_swaps)
	{
		pivot = array[index];
		swaps = 0;
		i = start;
		while (i < end)
		{
			if (array[i++] <= pivot)
				swaps++;
		}
		swaps = end - start - swaps;
		if (swaps < 0)
			swaps *= -1;
		index++;
	}
	return (pivot);
}

int	get_pivot_b(int *array, int start, int end)
{
	int	swaps;
	int	index;
	int	pivot;
	int	i;

	index = start;
	while (swaps != 3 && index <= end)
	{
		pivot = array[index];
		swaps = 0;
		i = start;
		while (i < end)
		{
			if (array[i++] <= pivot)
				swaps++;
		}
		index++;
	}
	if (swaps != 3)
	{
		index = start;
		while (swaps != 2 && index <= end)
		{
			pivot = array[index];
			swaps = 0;
			i = start;
			while (i < end)
			{
				if (array[i++] <= pivot)
					swaps++;
			}
			index++;
		}
	}
	if (swaps != 2)
	{
		index = start;	
		while (swaps != 1 && index <= end)
		{
			pivot = array[index];
			swaps = 0;
			i = start;
			while (i < end)
			{
				if (array[i++] <= pivot)
					swaps++;
			}
			index++;
		}		
	}
	return (pivot);
}

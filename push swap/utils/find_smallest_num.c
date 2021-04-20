/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:04:28 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/13 19:34:14 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Finds the index of the smallest number in the current status of the array;
** If capped, it finds the smallest number bigger than cap value;
** If provided, the value of the smallest number found is stored in "value"
*/

int	find_smallest_num(t_array_info *arrays, int *value, t_bool capped,
	int cap_value)
{
	int	index;
	int	aux;
	int	i;

	index = 0;
	i = 0;
	if (!capped || arrays->array_a[0] != cap_value)
		aux = arrays->array_a[0];
	else
		aux = arrays->array_a[1];
	printf("Capped: %i; Previous num = %i; ", capped, cap_value);
	while (i < arrays->array_a_length)
	{
		if (arrays->array_a[i] < aux
			&& (!capped || arrays->array_a[i] > cap_value))
		{
			index = i;
			aux = arrays->array_a[i];
		}
		i++;
	}
	if (value)
		*value = aux;
	printf("Found num: %i\n", aux);
	return (index);	
}

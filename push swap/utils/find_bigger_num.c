/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bigger_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:04:28 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/07 17:09:14 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Finds the index of the biggest number in the current status of the array;
** If capped, it finds the biggest number smaller than cap value;
** If provided, the value of the biggest number found is stored in "value"
*/

int	find_bigger_num(t_array_info *arrays, int *value, t_bool capped,
	int cap_value)
{
	int	index;
	int	aux;
	int	i;

	index = 0;
	i = 0;
	aux = arrays->array_a[0];
	while (i < arrays->array_a_length)
	{
		if (arrays->array_a[i] > aux
			&& (!capped || arrays->array_a[i] >= cap_value))
		{
			index = i;
			aux = arrays->array_a[i];
		}
		i++;
	}
	if (value)
		*value = aux;
	return (index);	
}

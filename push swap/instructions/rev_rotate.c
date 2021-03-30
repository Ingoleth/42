/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:12:54 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 19:55:30 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(int *array)
{
	int	i;
	int	aux;

	if (!array || !array[0])
		return ;
	i = get_array_length(array) - 1;
	aux = array[i];
	while (i > 0)
	{
		array[i] = array[i - 1];
		i--;
	}
	array[0] = aux;
}

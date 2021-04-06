/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:21:32 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/06 11:49:57 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
/*
**El primer número acaba al final del stack; 
*/
void	rotate(int *array, int length)
{
	int	i;
	int	aux;

	printf("Array length = %i; array[0] = %i\n", length, array[0]);
	if (!array || !length)
		return ;
	aux = array[0];
	length--;
	i = 0;
	while (i < length)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = aux;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:21:32 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/06 13:59:24 by aiglesia         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:12:54 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/01 21:19:29 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**El útimo número acaba al ppo del stack 
*/
void	rev_rotate(int *array, int length)
{
	int	aux;

	if (!array || length < 2)
		return ;
	length--;
	aux = array[length];
	while (length > 0)
	{
		array[length] = array[length - 1];
		length--;
	}
	array[0] = aux;
}

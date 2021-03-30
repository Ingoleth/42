/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:12:12 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 02:20:45 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(int *dst, int *src)
{
	int i;

	int aux;
	if (!dst || !src || !src[0])
		return ;
	i = get_array_length(dst) - 1;
	while (i)
	{
		dst[i] = dst[i - 1];
		i--;
	}
	dst[i] = src[0];
	aux = get_array_lenght(dst) - 1;
	i = aux;
	while (i >= 0)
	{
		src[i] = src[i + 1];
		i++;
	}
	src[aux] = 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:12:12 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 19:54:32 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *dst, int *src)
{
	int	aux;

	if (!dst || !src || !src[0])
		return ;
	aux = get_array_length(dst);
	dst[aux] = src[0];
	rev_rotate(dst);
	aux = 0;
	while (src[aux])
	{
		src[aux] = src[aux + 1];
		aux++;
	}
}

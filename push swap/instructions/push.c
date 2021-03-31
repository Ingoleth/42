/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:12:12 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 18:41:49 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *dst, int *src, int *dst_length, int *src_length)
{
	int	aux;
	int i;

	if (!dst || !src || *src_length == 0)
		return ;
	aux = *src_length;
	dst[*dst_length] = src[0];
	*dst_length += 1;
	rev_rotate(dst, *dst_length);
	i = 0;
	while (i < aux)
	{
		src[i] = src[i + 1];
		i++;
	}
	*src_length -= 1;
}

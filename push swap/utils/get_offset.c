/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:06:50 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/07 17:08:30 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_offset(t_array_info *arrays, int i)
{
	if (i >= arrays->current_index)
		return (i - arrays->current_index);
	return (i + arrays->array_a_length - arrays->current_index);
}

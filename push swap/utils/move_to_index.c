/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:48:57 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/05 12:33:06 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_vector_index_left(t_array_info *arrays, int index,
	t_bool * move_right)
{
	if (arrays->current_index - index
		< arrays->array_a_length - arrays->current_index + index)
		*move_right = false;
	else
		*move_right = true;
}

void	get_vector_index_right(t_array_info *arrays, int index,
	t_bool * move_right)
{
	if (index - arrays->current_index
		< arrays->array_a_length - index + arrays->current_index)
		*move_right = true;
	else
		*move_right = false;
}

void	move_to_index(t_array_info *arrays, int index)
{
	t_bool move_right;

	if (index < 0 || index > arrays->array_a_length
		|| index == arrays->current_index)
		return ;
	if (index < arrays->current_index)
		get_vector_index_left(arrays, index, &move_right);
	else
		get_vector_index_right(arrays, index, &move_right);
	if (move_right)
	{
		while (arrays->current_index != index)
			instruction(rot_a, arrays);
	}
	else
	{
		while (arrays->current_index != index)
			instruction(rev_rot_a, arrays);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_over_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:48:00 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/04 17:40:55 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_over_stack(t_array_info *arrays, int fd, int stack)
{
	int	i;

	i = 2;
	if (stack == array_a)
	{
		while (i--)
			push_num(arrays, fd, array_b, smaller);
		sort_3_over_stack(arrays, fd, array_a);
		instruction(push_a, fd, arrays);
		instruction(push_a, fd, arrays);
	}
	else
	{
		while (i--)
			push_num(arrays, fd, array_a, bigger);
		sort_3_over_stack(arrays, fd, array_b);
		instruction(push_b, fd, arrays);
		instruction(push_b, fd, arrays);
	}
}

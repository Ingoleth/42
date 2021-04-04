/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:36:59 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/03 19:36:21 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	regular_sort(t_array_info *arrays, int fd)
{
	while (arrays->array_a_length > 5)
		push_num(arrays, fd, array_b, smaller);
	sort_5_over_stack(arrays, fd, array_a);
	while (arrays->array_b_length)
		instruction(push_a, fd, arrays);	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:41:19 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 13:11:55 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *array_a, int *array_b, int fd)
{
	while (true)
	{
		if (array_a[0] > array_a[1])
			instruction(swap_a, fd, array_a, array_b);
		else if (array_a[0])
			instruction(push_b, fd, array_a, array_b);
		if (array_b[0] < array_b[1])
			instruction(swap_b, fd, array_a, array_b);
		if (!array_a[0] || !array_a[1])
			break ;
		print_stacks(array_a, array_b);
	}
	while (array_b[0])
		instruction(push_a, fd, array_a, array_b);
	ft_printf(fd, "\n");
	print_stacks(array_a, array_b);
}

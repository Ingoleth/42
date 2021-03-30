/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:52:33 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 13:22:25 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(int *array_a, int *array_b)
{
	t_bool a_done;
	t_bool b_done;
	int i;

	a_done = false;
	b_done = false;
	i = 0;
	while (a_done != true || b_done != true)
	{
		if (a_done == false && array_a[i])
			printf("[%7d]", array_a[i]);
		else if (a_done == false)
			a_done = true;
		if (!b_done && a_done)
			printf("[       ]");
		if (b_done == false && array_b[i])
			printf(" [%7d]", array_b[i]);
		else if (b_done == false)
			b_done = true;
		if (!a_done && b_done)
			printf(" [       ]");
		printf("\n");
		i++;
	}
	printf("    a         b\n\n");
}
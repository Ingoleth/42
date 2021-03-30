/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:52:33 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 18:31:24 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(int *array_a, int *array_b)
{
	int i;

	i = 0;
	while (array_a[i] || array_b[i])
	{
		if (array_a[i])
			printf("[%7d]", array_a[i]);
		else if (array_b[i])
			printf("[       ]");
		if (array_b[i])
			printf(" [%7d]b", array_b[i]);
		else if (array_a[i])
			printf(" [       ]b");
		printf("\n");
		i++;
	}
	printf("    a         b\n\n");
}
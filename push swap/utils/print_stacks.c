/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:52:33 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/27 19:32:38 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(t_array_info *arrays)
{
	int	i;

	printf("Array = ");
	if (arrays->current_index == 0)
	{
		i = 0;
		while (i < arrays->array_a_length)
			printf("%d ", arrays->array_a[i++]);
	}
	else
	{
		i = arrays->array_a_length - arrays->current_index;
		while (i < arrays->array_a_length)
			printf("%d ", arrays->array_a[i++]);
		i = 0;
		while (i <= arrays->array_a_length - arrays->current_index - 1)
			printf("%d ", arrays->array_a[i++]);
	}
	printf("\n");
}

int	get_colour_a(t_array_info *arrays, int i, unsigned short instruction)
{
	if (i + arrays->array_a_offset
		>= arrays->array_a_length - arrays->sorted_elements_a
		&& i < arrays->array_a_length - arrays->array_a_offset)
		return (32);
	if (instruction == push_a && i == 0)
		return (33);
	else if (instruction == swap_a && i <= 1)
		return (34);
	else if (instruction == rot_a || instruction == rot_a_and_b)
		return (35);
	else if (instruction == rev_rot_a || instruction == rev_rot_a_and_b)
		return (31);
	return (0);
}

int	get_colour_b(int i, unsigned short instruction)
{
	if (instruction == push_b && i == 0)
		return (33);
	else if (instruction == swap_b && i <= 1)
		return (34);
	else if (instruction == rot_b || instruction == rot_a_and_b)
		return (35);
	else if (instruction == rev_rot_b || instruction == rev_rot_a_and_b)
		return (31);
	return (0);
}

void	print_legend(void)
{
	printf("Push = [\033[%im***\033[0m]\n", 33);
	printf("Swap = [\033[%im***\033[0m]\n", 34);
	printf("Rotate = [\033[%im***\033[0m]\n", 35);
	printf("Rev rotate = [\033[%im***\033[0m]\n", 31);
}

void	print_stacks(t_array_info *arrays, unsigned short int instruction)
{
	int	i;

	i = 0;
	if (arrays->display_operations)
		printf("\033[2J");
	while (i < arrays->array_a_length || i < arrays->array_b_length)
	{
		printf("(%3d) ", i);
		if (i < arrays->array_a_length)
			printf("[\033[%im%7d\033[0m]",
				get_colour_a(arrays, i, instruction), arrays->array_a[i]);
		else if (arrays->array_b_length)
			printf("[       ]");
		if (i < arrays->array_b_length)
			printf(" [\033[%im%7d\033[0m]",
				get_colour_b(i, instruction), arrays->array_b[i]);
		else if (i < arrays->array_a_length)
			printf(" [       ]");
		printf("\n");
		i++;
	}
	printf("          a         b\n\n");
	printf("A size = %i; B size = %i;\n\n", arrays->array_a_length,
		arrays->array_b_length);
	print_legend();
	if (arrays->display_operations)
		sleep(1);
}

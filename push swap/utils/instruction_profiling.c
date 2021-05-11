/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:04:07 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/06 12:01:39 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	instr_swap(unsigned int instruction, t_array_info *arrays)
{
	if (instruction == swap_a)
		swap(arrays->array_a, arrays->array_a_length);
	else if (instruction == swap_b)
		swap(arrays->array_b, arrays->array_b_length);
	else if (instruction == swap_a_and_b)
	{
		swap(arrays->array_a, arrays->array_a_length);
		swap(arrays->array_b, arrays->array_b_length);
	}
}

static void	instr_push(unsigned int instruction, t_array_info *arrays)
{
	if (instruction == push_a)
		push(arrays->array_a, arrays->array_b, &arrays->array_a_length,
			&arrays->array_b_length);
	else if (instruction == push_b)
		push(arrays->array_b, arrays->array_a, &arrays->array_b_length,
			&arrays->array_a_length);
}

static void	instr_rotate(unsigned int instruction, t_array_info *arrays)
{
	if (instruction == rot_a)
		rotate(arrays->array_a, arrays->array_a_length);
	else if (instruction == rot_b)
		rotate(arrays->array_b, arrays->array_b_length);
	else if (instruction == rot_a_and_b)
	{
		rotate(arrays->array_a, arrays->array_a_length);
		rotate(arrays->array_b, arrays->array_b_length);
	}
}

static void	instr_rev_rotate(unsigned int instruction, t_array_info *arrays)
{
	if (instruction == rev_rot_a)
		rev_rotate(arrays->array_a, arrays->array_a_length);
	else if (instruction == rev_rot_b)
		rev_rotate(arrays->array_b, arrays->array_b_length);
	else if (instruction == rev_rot_a_and_b)
	{
		rev_rotate(arrays->array_a, arrays->array_a_length);
		rev_rotate(arrays->array_b, arrays->array_b_length);
	}
}

/*
**Rotate: El primer número acaba al final del stack;
**Rev_rotate: El último número acaba al ppo del stack;
*/
void	instruction_profiling(unsigned short instruction, t_array_info *arrays)
{
	if (instruction <= swap_a_and_b)
		instr_swap(instruction, arrays);
	else if (instruction == push_a || instruction == push_b)
		instr_push(instruction, arrays);
	else if (instruction >= rot_a && instruction <= rot_a_and_b)
		instr_rotate(instruction, arrays);
	else if (instruction >= rev_rot_a && instruction <= rev_rot_a_and_b)
		instr_rev_rotate(instruction, arrays);
	if (arrays->log)
		print_stacks(arrays, instruction);
	arrays->instruction_counter++;
}

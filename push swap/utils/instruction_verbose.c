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
	{
		ft_lstadd_back(&arrays->instructions_list,
			ft_lstnew(ft_strdup("sa\n")));
		swap(arrays->array_a, arrays->array_a_length);
	}
	else if (instruction == swap_b)
	{
		ft_lstadd_back(&arrays->instructions_list,
			ft_lstnew(ft_strdup("sb\n")));
		swap(arrays->array_b, arrays->array_b_length);
	}
	else if (instruction == swap_a_and_b)
	{
		ft_lstadd_back(&arrays->instructions_list,
			ft_lstnew(ft_strdup("ss\n")));
		swap(arrays->array_a, arrays->array_a_length);
		swap(arrays->array_b, arrays->array_b_length);
	}
}

static void	instr_push(unsigned int instruction, t_array_info *arrays)
{
	if (instruction == push_a)
	{
		ft_lstadd_back(&arrays->instructions_list,
			ft_lstnew(ft_strdup("pa\n")));
		push(arrays->array_a, arrays->array_b, &arrays->array_a_length,
			&arrays->array_b_length);
		if (arrays->current_index == 0)
			arrays->current_index = arrays->array_a_length - 1;
	}
	else if (instruction == push_b)
	{
		ft_lstadd_back(&arrays->instructions_list,
			ft_lstnew(ft_strdup("pb\n")));
		push(arrays->array_b, arrays->array_a, &arrays->array_b_length,
			&arrays->array_a_length);
		if (arrays->current_index == arrays->array_a_length)
			arrays->current_index = 0;
	}
}

static void	instr_rotate(unsigned int instruction, t_array_info *arrays)
{
	if (instruction == rot_a)
	{
		ft_lstadd_back(&arrays->instructions_list,
			ft_lstnew(ft_strdup("ra\n")));
		rotate(arrays->array_a, arrays->array_a_length);
	}
	else if (instruction == rot_b)
	{
		ft_lstadd_back(&arrays->instructions_list,
			ft_lstnew(ft_strdup("rb\n")));
		rotate(arrays->array_b, arrays->array_b_length);
	}
	else if (instruction == rot_a_and_b)
	{
		ft_lstadd_back(&arrays->instructions_list,
			ft_lstnew(ft_strdup("rr\n")));
		rotate(arrays->array_a, arrays->array_a_length);
		rotate(arrays->array_b, arrays->array_b_length);
	}
	if (instruction != rot_b)
	{
		if (arrays->current_index == arrays->array_a_length - 1)
			arrays->current_index = 0;
		else
			arrays->current_index++;
	}
}

static void	instr_rev_rotate(unsigned int instruction, t_array_info *arrays)
{
	if (instruction == rev_rot_a)
	{
		ft_lstadd_back(&arrays->instructions_list,
			ft_lstnew(ft_strdup("rra\n")));
		rev_rotate(arrays->array_a, arrays->array_a_length);
	}
	else if (instruction == rev_rot_b)
	{
		ft_lstadd_back(&arrays->instructions_list,
			ft_lstnew(ft_strdup("rrb\n")));
		rev_rotate(arrays->array_b, arrays->array_b_length);
	}
	else if (instruction == rev_rot_a_and_b)
	{
		ft_lstadd_back(&arrays->instructions_list,
			ft_lstnew(ft_strdup("rrb\n")));
		rev_rotate(arrays->array_a, arrays->array_a_length);
		rev_rotate(arrays->array_b, arrays->array_b_length);
	}
	if (instruction != rev_rot_b)
	{
		if (arrays->current_index == 0)
			arrays->current_index = arrays->array_a_length - 1;
		else
			arrays->current_index--;
	}
}

/*
**Rotate: El primer número acaba al final del stack;
**Rev_rotate: El último número acaba al ppo del stack;
*/
void	instruction_verbose(unsigned int instruction, t_array_info *arrays)
{
	if (instruction <= swap_a_and_b)
		instr_swap(instruction, arrays);
	else if (instruction == push_a || instruction == push_b)
		instr_push(instruction, arrays);
	else if (instruction >= rot_a && instruction <= rot_a_and_b)
		instr_rotate(instruction, arrays);
	else if (instruction >= rev_rot_a && instruction <= rev_rot_a_and_b)
		instr_rev_rotate(instruction, arrays);
	print_stacks(arrays);
	arrays->instruction_counter++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:04:07 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/01 19:54:56 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	instr_swap(unsigned int instruction, int fd, t_array_info *arrays)
{
	if (instruction == swap_a)
	{
		ft_putstr_fd("sa\n", fd);
		swap(arrays->array_a, arrays->array_a_length);
	}
	else if (instruction == swap_b)
	{
		ft_putstr_fd("sb\n", fd);
		swap(arrays->array_b, arrays->array_b_length);
	}
	else if (instruction == swap_a_and_b)
	{
		ft_putstr_fd("ss\n", fd);
		swap(arrays->array_a, arrays->array_a_length);
		swap(arrays->array_b, arrays->array_b_length);
	}
}

static void	instr_push(unsigned int instruction, int fd, t_array_info *arrays)
{
	if (instruction == push_a)
	{
		ft_putstr_fd("pa\n", fd);
		push(arrays->array_a, arrays->array_b, &arrays->array_a_length,
			&arrays->array_b_length);
	}
	else if (instruction == push_b)
	{
		ft_putstr_fd("pb\n", fd);
		push(arrays->array_b, arrays->array_a, &arrays->array_b_length,
			&arrays->array_a_length);
	}
}

static void	instr_rotate(unsigned int instruction, int fd, t_array_info *arrays)
{
	if (instruction == rot_a)
	{
		ft_putstr_fd("ra\n", fd);
		rotate(arrays->array_a, arrays->array_a_length);
	}
	else if (instruction == rot_b)
	{
		ft_putstr_fd("rb\n", fd);
		rotate(arrays->array_b, arrays->array_b_length);
	}
	else if (instruction == rot_a_and_b)
	{
		ft_putstr_fd("rr\n", fd);
		rotate(arrays->array_a, arrays->array_a_length);
		rotate(arrays->array_b, arrays->array_b_length);
	}
}

static void	instr_rev_rotate(unsigned int instruction, int fd,
	t_array_info *arrays)
{
	if (instruction == rev_rot_a)
	{
		ft_putstr_fd("rra\n", fd);
		rev_rotate(arrays->array_a, arrays->array_a_length);
	}
	else if (instruction == rev_rot_b)
	{
		ft_putstr_fd("rrb\n", fd);
		rev_rotate(arrays->array_b, arrays->array_b_length);
	}
	else if (instruction == rev_rot_a_and_b)
	{
		ft_putstr_fd("rrb\n", fd);
		rev_rotate(arrays->array_a, arrays->array_a_length);
		rev_rotate(arrays->array_b, arrays->array_b_length);
	}
}

/*
**Rotate: El primer número acaba al final del stack;
**Rev_rotate: El último número acaba al ppo del stack;
*/
void	instruction(unsigned int instruction, int fd, t_array_info *arrays)
{
	if (instruction <= swap_a_and_b)
		instr_swap(instruction, fd, arrays);
	else if (instruction == push_a || instruction == push_b)
		instr_push(instruction, fd, arrays);
	else if (instruction >= rot_a && instruction <= rot_a_and_b)
		instr_rotate(instruction, fd, arrays);
	else if (instruction >= rev_rot_a && instruction <= rev_rot_a_and_b)
		instr_rev_rotate(instruction, fd, arrays);
	arrays->instruction_counter++;
}

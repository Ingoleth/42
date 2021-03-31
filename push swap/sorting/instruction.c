/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:04:07 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 12:58:50 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	instr_swap(unsigned int instruction, int fd, int *array_a,
	int *array_b)
{
	if (instruction == swap_a)
	{
		ft_putstr_fd("sa\n", fd);
		swap(array_a);
	}
	else if (instruction == swap_b)
	{
		ft_putstr_fd("sb\n", fd);
		swap(array_b);
	}
	else if (instruction == swap_a_and_b)
	{
		ft_putstr_fd("ss\n", fd);
		swap(array_a);
		swap(array_b);
	}
}

static void	instr_push(unsigned int instruction, int fd, int *array_a,
	int *array_b)
{
	if (instruction == push_a)
	{
		ft_putstr_fd("pa\n", fd);
		push(array_a, array_b);
	}
	else if (instruction == push_b)
	{
		ft_putstr_fd("pb\n", fd);
		push(array_b, array_a);
	}
}

static void	instr_rotate(unsigned int instruction, int fd, int *array_a,
	int *array_b)
{
	if (instruction == rot_a)
	{
		ft_putstr_fd("ra\n", fd);
		rotate(array_a);
	}
	else if (instruction == rot_b)
	{
		ft_putstr_fd("rb\n", fd);
		rotate(array_b);
	}
	else if (instruction == rot_a_and_b)
	{
		ft_putstr_fd("rr\n", fd);
		rotate(array_a);
		rotate(array_b);
	}
}

static void	instr_rev_rotate(unsigned int instruction, int fd, int *array_a,
	int *array_b)
{
	if (instruction == rev_rot_a)
	{
		ft_putstr_fd("rra\n", fd);
		rev_rotate(array_a);
	}
	else if (instruction == rev_rot_b)
	{
		ft_putstr_fd("rrb\n", fd);
		rev_rotate(array_b);
	}
	else if (instruction == rev_rot_a_and_b)
	{
		ft_putstr_fd("rrb\n", fd);
		rev_rotate(array_a);
		rev_rotate(array_b);
	}
}

void	instruction(unsigned int instruction, int fd, int *array_a,
	int *array_b)
{
	if (instruction <= swap_a_and_b)
		instr_swap(instruction, fd, array_a, array_b);
	else if (instruction == push_a || instruction == push_b)
		instr_push(instruction, fd, array_a, array_b);
	else if (instruction >= rot_a && instruction <= rot_a_and_b)
		instr_rotate(instruction, fd, array_a, array_b);
	else if (instruction >= rev_rot_a && instruction <= rev_rot_a_and_b)
		instr_rev_rotate(instruction, fd, array_a, array_b);
}

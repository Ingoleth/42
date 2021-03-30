/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:26:54 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 14:13:26 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_bool swap_instruction(char *line, int *array_a, int *array_b)
{
	if (!ft_strncmp(line, "sa", 3))
	{
		swap(array_a);
		return (true);
	}
	else if (!ft_strncmp(line, "sb", 3))
	{
		swap(array_b);
		return (true);
	}
	else if (!ft_strncmp(line, "ss", 3))
	{
		swap(array_a);
		swap(array_b);
		return (true);
	}
	return (false);
}

static	t_bool push_instruction(char *line, int *array_a, int *array_b)
{
	if (!ft_strncmp(line, "pa", 3))
	{
		push(array_a, array_b);
		return (true);
	}
	else if (!ft_strncmp(line, "pb", 3))
	{
		push(array_b, array_a);
		return (true);
	}
	return (false);
}

static	t_bool rotate_instruction(char *line, int *array_a, int *array_b)
{
	if (!ft_strncmp(line, "ra", 3))
	{
		rotate(array_a);
		return (true);
	}
	else if (!ft_strncmp(line, "rb", 3))
	{
		rotate(array_b);
		return (true);
	}
	else if (!ft_strncmp(line, "rr", 3))
	{
		rotate(array_a);
		rotate(array_b);
		return (true);
	}
	return (false);
}

static	t_bool rev_rotate_instruction(char *line, int *array_a, int *array_b)
{
	if (!ft_strncmp(line, "rra", 4))
	{
		rev_rotate(array_a);
		return (true);
	}
	else if (!ft_strncmp(line, "rrb", 4))
	{
		rev_rotate(array_b);
		return (true);
	}
	else if (!ft_strncmp(line, "rrr", 4))
	{
		rev_rotate(array_a);
		rev_rotate(array_b);
		return (true);
	}
	return (false);
}

void get_instructions(int *array_a, int *array_b, int fd)
{
	char *line;

	while (true)
	{
		line = read_input(fd);
		if (!ft_strncmp(line, "", 1))
		{
			free(line);
			break ;
		}
		if(!swap_instruction(line, array_a, array_b) &&
		!push_instruction(line, array_a, array_b) &&
		!rotate_instruction(line, array_a, array_b) &&
		!rev_rotate_instruction(line, array_a, array_b))
		{
			ft_printf(STDERR_FILENO, "KO");
			free(line);
			free(array_a);
			free(array_b);
			exit (-1);
		}
		free(line);
	}
}
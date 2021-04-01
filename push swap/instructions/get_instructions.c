/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:26:54 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 18:38:12 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_bool	swap_instruction(char *line, t_array_info *arrays)
{
	if (!ft_strncmp(line, "sa", 3))
	{
		swap(arrays->array_a, arrays->array_a_length);
		return (true);
	}
	else if (!ft_strncmp(line, "sb", 3))
	{
		swap(arrays->array_b, arrays->array_b_length);
		return (true);
	}
	else if (!ft_strncmp(line, "ss", 3))
	{
		swap(arrays->array_a, arrays->array_a_length);
		swap(arrays->array_b, arrays->array_b_length);
		return (true);
	}
	return (false);
}

static	t_bool	push_instruction(char *line, t_array_info *arrays)
{
	if (!ft_strncmp(line, "pa", 3))
	{
		push(arrays->array_a, arrays->array_b,
			&arrays->array_a_length, &arrays->array_b_length);
		return (true);
	}
	else if (!ft_strncmp(line, "pb", 3))
	{
		push(arrays->array_b, arrays->array_a,
			&arrays->array_b_length, &arrays->array_a_length);
		return (true);
	}
	return (false);
}

static	t_bool	rotate_instruction(char *line, t_array_info *arrays)
{
	if (!ft_strncmp(line, "ra", 3))
	{
		rotate(arrays->array_a, arrays->array_a_length);
		return (true);
	}
	else if (!ft_strncmp(line, "rb", 3))
	{
		rotate(arrays->array_b, arrays->array_b_length);
		return (true);
	}
	else if (!ft_strncmp(line, "rr", 3))
	{
		rotate(arrays->array_a, arrays->array_a_length);
		rotate(arrays->array_b, arrays->array_b_length);
		return (true);
	}
	return (false);
}

static	t_bool	rev_rotate_instruction(char *line, t_array_info *arrays)
{
	if (!ft_strncmp(line, "rra", 4))
	{
		rev_rotate(arrays->array_a, arrays->array_a_length);
		return (true);
	}
	else if (!ft_strncmp(line, "rrb", 4))
	{
		rev_rotate(arrays->array_b, arrays->array_b_length);
		return (true);
	}
	else if (!ft_strncmp(line, "rrr", 4))
	{
		rev_rotate(arrays->array_a, arrays->array_a_length);
		rev_rotate(arrays->array_b, arrays->array_b_length);
		return (true);
	}
	return (false);
}

void	get_instructions(t_array_info *arrays, int fd)
{
	char	*line;

	while (true)
	{
		line = read_input(fd);
		if (!ft_strncmp(line, "", 1))
		{
			free(line);
			break ;
		}
		if (!swap_instruction(line, arrays)
			&& !push_instruction(line, arrays)
			&& !rotate_instruction(line, arrays)
			&& !rev_rotate_instruction(line, arrays))
		{
			ft_printf(STDERR_FILENO, "KO");
			free(line);
			free(arrays->array_a);
			free(arrays->array_b);
			exit (-1);
		}
		free(line);
	}
}

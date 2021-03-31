/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions_verbose.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:36:39 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 20:49:10 by aiglesia         ###   ########.fr       */
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

static	t_bool	rotate_instruction(char *line,  t_array_info *arrays)
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

static	t_bool	rev_rotate_instruction(char *line,  t_array_info *arrays)
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

void	get_instructions_verbose(t_array_info *arrays, int fd)
{
	char	*line;

	print_stacks(arrays);
	while (true)
	{
		printf("Please input instructions:\n");
		printf("\033[2J");
		printf("\033[1000D");
		printf("\033[1000A");
		line = read_input(fd);
		if (!ft_strncmp(line, "", 1))
		{
			free(line);
			break ;
		}
		print_stacks(arrays);
		swap_instruction(line, arrays);
		push_instruction(line, arrays);
		rotate_instruction(line, arrays);
		rev_rotate_instruction(line, arrays);
		free(line);
	}
	printf("\n");
}

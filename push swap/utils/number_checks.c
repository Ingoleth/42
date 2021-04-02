/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:53:48 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 20:05:31 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_number(char *line)
{
	int	i;

	i = 0;
	if (ft_strchr("+-", line[0]))
		i++;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (false);
		i++;
	}
	return (true);
}

t_bool	is_repeated(int nb, t_list *array_list)
{
	if (array_list)
	{
		while (array_list)
		{
			if (((int *)array_list->content)[0] == nb)
				return (true);
			array_list = array_list->next;
		}
	}
	return (false);
}

t_bool	is_long_int(char *input)
{
	int		length;
	char	*cmp_str;

	while (ft_isspace(input[0]))
		input++;
	while (input [0] == '+')
		input++;
	cmp_str = "2147483647";
	if (input[0] == '-')
	{
		input++;
		cmp_str = "2147483648";
	}
	length = ft_strlen(input);
	if (length < 10)
		return (false);
	else if (length > 10)
		return (true);
	if (ft_strncmp(input, cmp_str, 10) > 0)
		return (true);
	return (false);
}

t_bool	is_sorted(int *array, int length, int direction)
{
	int	i;

	if (!array)
		return (false);
	if (length == 0)
		return (true);
	i = 1;
	while (i < length)
	{
		if (direction == ascending)
		{
			if (array[i] < array[i - 1])
				return (false);
		}
		else
		{
			if (array[i] > array[i - 1])
				return (false);
		}
		i++;
	}
	return (true);
}

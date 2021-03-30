/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_from_argv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:46:11 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 19:21:25 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_repeated_array(int nb, int *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (nb == array[i])
			return (true);
		i++;
	}
	return (false);
}

static void	print_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

int	*fill_array(char **argv, int size)
{
	int	*array;
	int	nb;

	array = ft_alloc(size, sizeof(int));
	if (array == NULL)
		print_error();
	size = 0;
	while (argv[size])
	{
		nb = ft_atoi(argv[size]);
		if (is_repeated_array(nb, array))
		{
			free(array);
			print_error();
		}
		array[size] = nb;
		size++;
	}
	return (array);
}

int	*get_array_from_argv(char **argv)
{
	int	size;

	size = 0;
	if (!argv[size])
		print_error();
	while (argv[size])
	{
		if (!is_number(argv[size]) || is_long_int(argv[size]))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(1);
		}
		size++;
	}
	return (fill_array(argv, size));
}

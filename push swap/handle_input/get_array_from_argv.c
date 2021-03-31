/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_from_argv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:46:11 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 18:38:12 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_repeated_array(int nb, int *array, int length)
{
	int	i;

	i = 0;
	while (i < length)
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

void	fill_array(char **argv, int argc, int argv_pos, t_array_info *arrays)
{
	int	nb;
	int	i;

	arrays->array_a	 = ft_alloc(argc - argv_pos, sizeof(int));
	arrays->array_a_length = argc - argv_pos;
	if (arrays->array_a == NULL)
		print_error();
	i = 0;
	while (argv_pos < argc)
	{
		nb = ft_atoi(argv[argv_pos]);
		if (is_repeated_array(nb, arrays->array_a, i))
		{
			free(arrays->array_a);
			print_error();
		}
		arrays->array_a[i] = nb;
		argv_pos++;
		i++;
	}
}

void	get_array_from_argv(char **argv, int argc, int argv_pos,
	t_array_info *arrays)
{
	int	i;

	i = argv_pos;
	if (!argv[i])
		print_error();
	while (i < argc)
	{
		if (!is_number(argv[i]) || is_long_int(argv[i]))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(1);
		}
		i++;
	}
	fill_array(argv, argc, argv_pos, arrays);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:39:13 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 20:13:55 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_random_input(char **argv, t_array_info *arrays, t_bool verbose, int argv_pos)
{
	if (argv[argv_pos + 1] && argv[argv_pos + 1])
	{
		if (verbose && !is_number(argv[argv_pos + 1]))
			ft_printf(STDERR_FILENO, "Array seed must be numeric!\n");
		else 
		{
			get_rand_array(ft_atoi(argv[argv_pos]), ft_atoi(argv[argv_pos + 1]), arrays);
			return ;
		}
	}
	else if (verbose)
	{
		if (!argv[0])
			ft_printf(STDERR_FILENO, "Array length and seed missing!\n");
		else
			ft_printf(STDERR_FILENO, "Random seed missing!\n");
	}
	exit(-1);
}
/*
** TODO: Check for more arguments --> error if found?
*/
void	handle_fd_array(char **argv, t_array_info *arrays, t_bool verbose)
{
	int	fd;

	fd = open(argv[0], O_RDONLY);
	if (fd == -1)
	{
		if (argv[0])
		{
			if (verbose)
				ft_printf(STDERR_FILENO, "Couldn't open input file!\n");
			else
				ft_printf(STDERR_FILENO, "KO\n");
		}
		exit(1);
	}
	get_input_array(fd, arrays, verbose);
	close(fd);
}

void	handle_input(int argc, char **argv, t_flags *flags, t_array_info *arrays)
{
	int argv_pos;

	if (argc == 1)
		exit(-1);
	argv_pos = 1;
	handle_flags(argv, flags, &argv_pos);
	if (flags->mode_input)
		get_input_array(STDIN_FILENO, arrays, flags->verbose);
	else if (flags->mode_fd)
		handle_fd_array(argv, arrays, flags->verbose);
	else if (flags->mode_rand)
		handle_random_input(argv, arrays, flags->verbose, argv_pos);
	else
		get_array_from_argv(argv, argc, argv_pos, arrays);
}

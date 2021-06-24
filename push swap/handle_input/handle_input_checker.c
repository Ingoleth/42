/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:39:13 by aiglesia          #+#    #+#             */
/*   Updated: 2021/06/22 12:20:33 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_random_input(char **argv, t_array_info *arrays,
	t_bool verbose, int argv_pos)
{
	if (argv[argv_pos + 1] && argv[argv_pos + 1])
	{
		if (verbose && (!is_number(argv[argv_pos + 1])
				|| !ft_atoi(argv[argv_pos + 1])))
			ft_printf(STDERR_FILENO, "Array seed must be numeric and != 0!\n");
		else
		{
			get_rand_array(ft_atoi(argv[argv_pos]),
				ft_atoi(argv[argv_pos + 1]), arrays);
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
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(-1);
}

void	handle_fd_array(char **argv, t_array_info *arrays,
	t_bool verbose)
{
	int	fd;

	fd = open("array", O_RDONLY);
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

t_bool	invalid_flag_combination(t_flags *flags)
{
	if ((flags->inst_mode_fd && flags->push_swap)
		|| ((flags->file_output || flags->log || flags->display_operations)
			&& flags->checker))
	{
		if (flags->verbose)
			ft_putstr_fd(
				"Input flag is not available in this mode!\n",
				STDIN_FILENO);
		else
			ft_putstr_fd("Error\n", STDERR_FILENO);
		return (true);
	}
	return (false);
}

void	handle_input(int argc, char **argv,
	t_flags *flags, t_array_info *arrays)
{
	int	argv_pos;

	if (argc == 1)
		exit(-1);
	argv_pos = 1;
	handle_flags(argv, flags, &argv_pos);
	if (invalid_flag_combination(flags))
		exit(-1);
	if (flags->mode_input)
		get_input_array(STDIN_FILENO, arrays, flags->verbose);
	else if (flags->mode_fd)
		handle_fd_array(argv, arrays, flags->verbose);
	else if (flags->mode_rand)
		handle_random_input(argv, arrays, flags->verbose, argv_pos);
	else
		get_array_from_argv(argv, argc, argv_pos, arrays);
}

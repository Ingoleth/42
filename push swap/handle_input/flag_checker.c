/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:54:55 by aiglesia          #+#    #+#             */
/*   Updated: 2021/06/21 13:56:24 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error_and_exit(char **flags_list, t_flags *flags,
		char **argv, int *argv_pos)
{
	ft_array_clear((void *)flags_list, free);
	if (flags->mode_argv && !argv[0][*argv_pos])
		exit(0);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

void	handle_functionality_flags(char **flags_list, char **argv,
	t_flags *flags, int *argv_pos)
{
	if (!ft_strncmp(argv[*argv_pos], "-do", 4))
	{
		if (flags->display_operations)
			print_error_and_exit(flags_list, flags, argv, argv_pos);
		flags->display_operations = true;
		flags->log = true;
		flags->verbose = true;
		printf("Hello!\n");
	}
	else if (!ft_strncmp(argv[*argv_pos], "-l", 3))
	{
		if (flags->log)
			print_error_and_exit(flags_list, flags, argv, argv_pos);
		flags->log = true;
		flags->verbose = true;
	}
	else if (!ft_strncmp(argv[*argv_pos], "-p", 3))
	{
		if (flags->profile)
			print_error_and_exit(flags_list, flags, argv, argv_pos);
		flags->profile = true;
	}
}

void	handle_input_flags(char **flags_list, char **argv,
	t_flags *flags, int *argv_pos)
{
	if (!ft_strncmp(argv[*argv_pos], "-ci", 4))
	{
		if (flags->mode_input || flags->mode_fd || flags->mode_rand)
			print_error_and_exit(flags_list, flags, argv, argv_pos);
		flags->mode_input = true;
	}
	else if (!ft_strncmp(argv[*argv_pos], "-fi", 4))
	{
		if (flags->mode_input || flags->mode_fd || flags->mode_rand)
			print_error_and_exit(flags_list, flags, argv, argv_pos);
		flags->mode_fd = true;
	}
	else if (!ft_strncmp(argv[*argv_pos], "-ra", 4))
	{
		if (flags->mode_input || flags->mode_fd || flags->mode_rand)
			print_error_and_exit(flags_list, flags, argv, argv_pos);
		flags->mode_rand = true;
	}
	else
		handle_functionality_flags(flags_list, argv, flags, argv_pos);
}

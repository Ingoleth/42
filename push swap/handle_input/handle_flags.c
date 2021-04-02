/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:57:16 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 18:38:12 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void
	print_error_and_exit(char **flags_list, t_flags *flags,
		char **argv, int *argv_pos)
{
	free(flags_list);
	if (flags->mode_argv && !argv[0][*argv_pos])
		exit(0);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
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
	else if (!ft_strncmp(argv[*argv_pos], "-ifi", 5))
	{
		if (flags->inst_mode_fd)
			print_error_and_exit(flags_list, flags, argv, argv_pos);
		flags->inst_mode_fd = true;
	}
}

static	t_bool	check_flags(char **flags_list, char *str)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(str) + 1;
	while (flags_list[i])
	{
		if (!ft_strncmp(str, flags_list[i], length))
			return (true);
		i++;
	}
	return (false);
}

static	void	check_argv_mode(t_flags *flags, char **argv,
	char **flags_list, int *argv_pos)
{
	if (!flags->mode_fd && !flags->mode_input && !flags->mode_rand)
		flags->mode_argv = true;
	if (flags->mode_argv && !argv[0][*argv_pos])
		print_error_and_exit(flags_list, flags, argv, argv_pos);
}

void	handle_flags(char **argv, t_flags *flags, int *argv_pos)
{
	char	**flags_list;

	flags_list = ft_split("-ci -fi -ra -ifi -v -fo", ' ');
	ft_memset(flags, 0, sizeof(t_flags));
	while (argv[*argv_pos] && check_flags(flags_list, argv[*argv_pos]))
	{
		if (!ft_strncmp(argv[*argv_pos], "-v", 3))
		{
			if (flags->verbose == true)
				print_error_and_exit(flags_list, flags, argv, argv_pos);
			flags->verbose = true;
		}
		else if (!ft_strncmp(argv[*argv_pos], "-fo", 4))
		{
			if (flags->file_output == true)
				print_error_and_exit(flags_list, flags, argv, argv_pos);
			flags->file_output = true;
		}
		handle_input_flags(flags_list, argv, flags, argv_pos);
		(*argv_pos)++;
	}
	check_argv_mode(flags, argv, flags_list, argv_pos);
	free(flags_list);
}

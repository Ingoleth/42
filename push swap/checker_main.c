/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:22:26 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 11:02:11 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	handle_instructions(int *array_a, int *array_b, t_flags *flags)
{
	int	fd;

	fd = 0;
	if (flags->inst_mode_fd)
	{
		fd = open("instuctions", O_RDONLY);
		if (fd == -1)
		{
			if (flags->verbose)
				ft_printf(STDERR_FILENO, "Couldn't open instructions file!\n");
			else
				ft_printf(STDERR_FILENO, "KO\n");
			free(array_a);
			free(array_b);
			exit(-1);
		}
	}
	if (flags->verbose)
		get_instructions_verbose(array_a, array_b, fd);
	else
		get_instructions(array_a, array_b, fd);
}

static	void	
	print_result(int *array_a, int *array_b, t_flags *flags)
{
	if (!get_array_length(array_b) && is_sorted(array_a))
	{
		if (flags->verbose)
			printf("Array is sorted!\n");
		else
			ft_printf(STDERR_FILENO, "OK\n");
	}
	else
	{
		if (flags->verbose)
			printf("Array is not sorted!\n");
		else
			ft_printf(STDERR_FILENO, "KO\n");
	}
}

int	main(int argc, char **argv)
{
	int		*array_a;
	int		*array_b;
	t_flags	flags;

	if (argc == 1)
		return (0);
	flags = initialize_arrays(argc, argv, &array_a, &array_b);
	handle_instructions(array_a, array_b, &flags);
	print_result(array_a, array_b, &flags);
	free(array_a);
	free(array_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:22:26 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 20:06:56 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	handle_instructions(t_array_info *arrays, t_flags *flags)
{
	int	fd;

	fd = 0;
	if (flags->inst_mode_fd)
	{
		fd = open("instructions_list", O_RDONLY);
		if (fd == -1)
		{
			if (flags->verbose)
				ft_printf(STDERR_FILENO, "Couldn't open instructions file!\n");
			else
				ft_printf(STDERR_FILENO, "KO\n");
			free(arrays->array_a);
			free(arrays->array_b);
			exit(-1);
		}
	}
	if (flags->verbose)
		get_instructions_verbose(arrays, fd);
	else
		get_instructions(arrays, fd);
}

static	void	print_result(t_array_info *arrays, t_flags *flags)
{
	if (!arrays->array_b_length
		&& is_sorted(arrays->array_a, arrays->array_a_length))
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
	t_array_info	arrays;
	t_flags			flags;

	if (argc == 1)
		return (0);
	initialize_arrays(argc, argv, &arrays, &flags);
	handle_instructions(&arrays, &flags);
	print_result(&arrays, &flags);
	free(arrays.array_a);
	free(arrays.array_b);
}

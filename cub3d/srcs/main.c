/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:44:52 by user42            #+#    #+#             */
/*   Updated: 2020/12/21 13:15:49 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_initial_arguments(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("Error\nNo input file.\n", 1);
		exit(-1);
	}
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
	{
		ft_putstr_fd("Error\nInvalid second argument.\n", 1);
		exit(-1);
	}
	if (argc > 3)
	{
		ft_putstr_fd("Error\nToo many arguments.\n", 1);
		exit(-1);
	}
}

int		main(int argc, char **argv)
{
	t_cub3d data;

	handle_initial_arguments(argc, argv);
	ft_memset(&data, 0, sizeof(t_cub3d));
	if (!(data.mlx_data.mlx_ptr = mlx_init()))
		return (0);
	if (argc == 3)
		handle_screenshot(argv[1], &data);
	if (!initialize_render_data(&data.mlx_data, &data, argv[1]))
		cleanup(&data);
	mlx_hook(data.mlx_data.win_ptr, 2, 1L << 0, on_key_pressed, &data);
	mlx_hook(data.mlx_data.win_ptr, 3, 1L << 1, on_key_released,
	&data.mlx_data);
	mlx_hook(data.mlx_data.win_ptr, 33, 0, cleanup, &data);
	mlx_hook(data.mlx_data.win_ptr, 9, 1L << 21, redraw_screen, &data);
	mlx_loop_hook(data.mlx_data.mlx_ptr, check_keys, &data);
	mlx_loop(data.mlx_data.mlx_ptr);
	data.mlx_data.win_ptr = 0;
	cleanup(&data);
}

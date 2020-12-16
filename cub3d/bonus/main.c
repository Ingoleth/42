/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:44:52 by user42            #+#    #+#             */
/*   Updated: 2020/12/16 19:28:54 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	cub3d data;

	if (argc < 2)
	{
		ft_putstr_fd("Error:\nNo input file.\n", 1);
		return (-1);
	}
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
	{
		ft_putstr_fd("Error:\nInvalid second argument.\n", 1);
		return (-1);
	}
	ft_memset(&data, 0, sizeof(cub3d));
	if (!(data.mlx_data.mlx_ptr = mlx_init()) ||
	!initialize_render_data(&data.mlx_data, &data, argv[1]))
		cleanup(&data);
	if (argc == 3)
		take_screenshot(data.mlx_data.background);
	mlx_hook(data.mlx_data.win_ptr, 2, 1L << 0, on_key_pressed, &data);
	mlx_hook(data.mlx_data.win_ptr, 3, 1L << 1, on_key_released,
	&data.mlx_data);
	mlx_hook(data.mlx_data.win_ptr, 9, 1L << 21, redraw_screen, &data);
	mlx_loop_hook(data.mlx_data.mlx_ptr, check_keys, &data);
	mlx_loop(data.mlx_data.mlx_ptr);
	data.mlx_data.win_ptr = 0;
	cleanup(&data);
}

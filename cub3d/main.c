/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:44:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/09 14:11:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

int main (void)
{
	cub3d data;

	data.mlx_data.mlx_ptr = mlx_init();
	if (!(data.render_data = initialize_render_data(&data.mlx_data)))
		return (0);;
	mlx_key_hook(data.mlx_data.win_ptr, handle_keys, &data);
	mlx_loop_hook(data.mlx_data.win_ptr, redraw_screen, &data);
	mlx_loop(data.mlx_data.mlx_ptr);
	free_render_data(data.render_data);
	return (0);
}
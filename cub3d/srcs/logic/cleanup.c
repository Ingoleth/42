/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:47:37 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/17 00:02:52 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cleanup(cub3d *data)
{
	if (data->mlx_data.background)
		free_image(data->mlx_data.mlx_ptr, data->mlx_data.background);
	free_render_data(&data->render_data, data->mlx_data.mlx_ptr);
	if (data->mlx_data.win_ptr)
		mlx_destroy_window(data->mlx_data.mlx_ptr, data->mlx_data.win_ptr);
	mlx_destroy_display(data->mlx_data.mlx_ptr);
	free(data->mlx_data.mlx_ptr);
	exit(0);
	return (0);
}

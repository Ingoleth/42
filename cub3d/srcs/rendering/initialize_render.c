/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:33:22 by user42            #+#    #+#             */
/*   Updated: 2020/12/20 13:53:08 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		initialize_render_data(t_mlx *mlx_data, t_cub3d *data, char *file_path)
{
	if (!read_file(file_path, &data->render_data, mlx_data->mlx_ptr) ||
	check_render_data(&data->render_data, mlx_data->mlx_ptr))
		return (0);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr,
	data->render_data.res_x, data->render_data.res_y, "Cub3d");
	mlx_data->background = initialize_image(mlx_data->mlx_ptr,
	data->render_data.res_x, data->render_data.res_y);
	data->render_data.column_height = data->render_data.res_x /
	(tan(FOV / 2) * 2);
	redraw_screen(data);
	return (1);
}

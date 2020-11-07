/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:57:41 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/07 17:26:07 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_column(int i, float distance, cub3d *data)
{
	int y_axis;
	int column_size;
	int j;

	y_axis = data->render_data->res_y / 2;
	column_size = (int)(data->ray_trc.column_height / (distance * 2));
	column_size = column_size > y_axis - 1 ? y_axis - 1 : column_size;
	column_size = y_axis;
	j = 0;
	while (j < column_size)
	{
		draw_pixel(data->mlx_data.background, i, y_axis + j, RED);
		draw_pixel(data->mlx_data.background, i, y_axis - j, RED);
		j++;
	}
	while (get_pixel(data->mlx_data.background, i, j) != data->render_data->c_rgb)
	{
		draw_pixel(data->mlx_data.background, i, j, data->render_data->c_rgb);
		draw_pixel(data->mlx_data.background, i, y_axis - j, data->render_data->f_rgb);
	}
}
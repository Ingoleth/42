/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:57:41 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/08 11:17:04 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int get_colour(int i)
{
	if (i == 0)
		return (RED);
	if (i == 1)
		return (YELLOW);
	if (i == 2)
		return (PURPLE);
	else
		return (CYAN);
}

void draw_column(int i, float distance, cub3d *data)
{
	int y_axis;
	int column_size;
	int j;

	y_axis = data->render_data->res_y / 2;
	column_size = (int)(data->ray_trc.column_height / (distance));
	j = 0;
	while (j < column_size)
	{
		draw_pixel(data->mlx_data.background, i, y_axis + j, get_colour(data->ray_trc.cardinal_collision));
		draw_pixel(data->mlx_data.background, i, y_axis - j, get_colour(data->ray_trc.cardinal_collision));
		j++;
	}
	while (j < y_axis)
	{
		draw_pixel(data->mlx_data.background, i, y_axis - j, data->render_data->c_rgb);
		draw_pixel(data->mlx_data.background, i, y_axis + j, data->render_data->f_rgb);
		j++;
	}
}
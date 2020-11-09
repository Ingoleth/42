/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:57:41 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/09 20:20:24 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int get_image_colour(cub3d *data, int column_size, int j)
{
	t_data *image;
	int i;
	int k;

	if(data->ray_trc.cardinal_collision == NORTH)
		image = &data->render_data->north_texture;
	else if(data->ray_trc.cardinal_collision == WEST)
		image = &data->render_data->west_texture;
	else if(data->ray_trc.cardinal_collision == SOUTH)
		image = &data->render_data->south_texture;
	else
		image = &data->render_data->east_texture;
	k = (int)(image->height * (0.5 + (0.5 * j / column_size)));
	if (data->ray_trc.cardinal_collision == NORTH || data->ray_trc.cardinal_collision == SOUTH)
		i = (int)(image->width * (data->ray_trc.x_collision - (int)data->ray_trc.x_collision));
	else
		i = (int)(image->width * (data->ray_trc.y_collision - (int)data->ray_trc.y_collision));
	return (get_pixel(image, i, k));
}


void draw_column(int i, float distance, cub3d *data)
{
	int y_axis;
	int column_size;
	int j;

	y_axis = data->render_data->res_y / 2;
	column_size = (int)(data->ray_trc.column_height / (distance));
	column_size = column_size > y_axis ? y_axis : column_size;
	j = 0;
	while (j < column_size)
	{
		draw_pixel(data->mlx_data.background, i, y_axis + j, get_image_colour(data, column_size, j));
		draw_pixel(data->mlx_data.background, i, y_axis - j, get_image_colour(data, column_size, -j));
		j++;
	}
	while (get_pixel(data->mlx_data.background, i, y_axis - j) != data->render_data->c_rgb && j < y_axis)
	{
		draw_pixel(data->mlx_data.background, i, y_axis - j, data->render_data->c_rgb);
		draw_pixel(data->mlx_data.background, i, y_axis + j, data->render_data->f_rgb);
		j++;
	}
}
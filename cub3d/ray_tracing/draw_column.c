/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:57:41 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/06 18:06:47 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


unsigned int		add_shade(unsigned int colour, double distance, float shade_distance)
{
	int r, g, b;
	r = get_r(colour);
	g = get_g(colour);
	b = get_b(colour);

	if (distance > shade_distance)
		distance = shade_distance;
	distance /= shade_distance;
	distance -= distance > 0.05 ? 0.05 : 0;
	r = r - (r * distance);
	g = g - (g * distance);
	b = b - (b * distance);
	return (get_trgb(get_t(colour), r, g, b));
}

t_data *get_texture_to_render(int index, s_render_data *render_data)
{
	if(index == NORTH)
		return (&render_data->north_texture);
	else if(index == WEST)
		return (&render_data->west_texture);
	else if(index == SOUTH)
		return (&render_data->south_texture);
	else
		return (&render_data->east_texture);
}

unsigned int get_image_colour(cub3d *data, int column_size, int img_y)
{
	t_data *image;
	int x;
	int y;
	
	image = get_texture_to_render(data->ray_trc.cardinal_collision, &data->render_data);
	y = (int)(image->height * img_y / (float)column_size);
	if (data->ray_trc.cardinal_collision == NORTH || data->ray_trc.cardinal_collision == SOUTH)
		x = (int)(image->width * (data->ray_trc.x_collision - (int)data->ray_trc.x_collision));
	else
		x = (int)(image->width * (data->ray_trc.y_collision - (int)data->ray_trc.y_collision));
	return (get_pixel(image, x, y));
}

void draw_column(int i, float distance, cub3d *data, int y_offset)
{
	int column_size;
	int starting_position;
	int j;
	column_size = (int)(data->render_data.column_height / (distance));
	starting_position = data->render_data.res_y / 2 - column_size / 2 + y_offset;
	j = starting_position < 0 ? -starting_position : 0;
	while (j++ < column_size && starting_position + j < data->render_data.res_y)
		draw_pixel(data->mlx_data.background, i, starting_position + j, add_shade(get_image_colour(data, column_size, j), distance, data->render_data.shade_distance));
	
}
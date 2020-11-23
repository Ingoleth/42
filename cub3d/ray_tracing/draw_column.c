/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:57:41 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/23 17:45:13 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


unsigned int		add_shade(unsigned int colour, double distance)
{
	int r, g, b;
	r = get_r(colour);
	g = get_g(colour);
	b = get_b(colour);

	if (distance > SHADE_DISTANCE)
		distance = SHADE_DISTANCE;
	distance /= SHADE_DISTANCE;
	distance -= 0.2;
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
	else if(index == EAST)
		return (&render_data->east_texture);
	else
		return (&render_data->sprite);
}

unsigned int get_image_colour(cub3d *data, int column_size, int img_y)
{
	t_data *image;
	int x;
	int y;
	
	image = get_texture_to_render(data->ray_trc.cardinal_collision, &data->render_data);
	y = (int)(image->height * (0.5 + (0.5 * img_y / column_size)));
	if (data->ray_trc.cardinal_collision == NORTH || data->ray_trc.cardinal_collision == SOUTH)
		x = (int)(image->width * (data->ray_trc.x_collision - (int)data->ray_trc.x_collision));
	else
		x = (int)(image->width * (data->ray_trc.y_collision - (int)data->ray_trc.y_collision));
	return (get_pixel(image, x, y));
}

void draw_column(int i, float distance, cub3d *data)
{
	int y_axis;
	int column_size;
	int max_draw_height;
	int j;

	y_axis = data->render_data.res_y / 2;
	column_size = (int)(data->ray_trc.column_height / (distance));
	max_draw_height = column_size > y_axis ? y_axis : column_size;
	j = 0;
	while (j < max_draw_height) //Move to a different function, check for sprite in a while to avoid double drawing...
	{
		draw_pixel(data->mlx_data.background, i, y_axis + j, add_shade(get_image_colour(data, column_size, j), distance));
		draw_pixel(data->mlx_data.background, i, y_axis - j, add_shade(get_image_colour(data, column_size, -j), distance));
		j++;
	}
	while (get_pixel(data->mlx_data.background, i, y_axis - j) != data->render_data.c_rgb && j < y_axis)
	{
		draw_pixel(data->mlx_data.background, i, y_axis - j, data->render_data.c_rgb);
		draw_pixel(data->mlx_data.background, i, y_axis + j, data->render_data.f_rgb);
		j++;
	}
}
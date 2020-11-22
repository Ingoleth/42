/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:06:53 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/22 17:12:00 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_bool check_wall_collision(int tile_value, int tile_coord, s_ray_tracing * ray_trc, t_bool horiz)
{
	if(tile_value == '1') // Change it so the thing is not turbo guarra
	{
		if (horiz)
			ray_trc->y_collision = tile_coord;
		else
			ray_trc->x_collision = tile_coord;
		return (true);
	}
	if (tile_value == '2')
	{
		if (horiz)
		{
			ray_trc->sprite = tile_value;
			ray_trc->sprite_x = ray_trc->x_collision;
			ray_trc->sprite_y = tile_coord;
		}
		else
		{
			ray_trc->sprite = -tile_value;
			ray_trc->sprite_x = tile_coord;
			ray_trc->sprite_y = ray_trc->y_collision;
		}
	}
	return (false);
}

unsigned int get_sprite_colour(cub3d *data, int column_size, int img_y)
{
	t_data *image;
	int x;
	int y;
	float max_size;

	return (RED);
	image = &data->render_data.sprite;
	max_size = fabs(cos(data->render_data.view_angle)) + fabs(cos(data->render_data.view_angle));
	x = (int)(image->width * (get_sprite_horizontal_lenght(&data->ray_trc, data->render_data.view_angle) / max_size));
	y = (int)(image->height * (0.5 + (0.5 * img_y / column_size)));

	return (get_pixel(image, x, y)); // Add a check to only return something if non-transparent!
}

float get_sprite_distance (float player_x, float player_y, float sprite_x, float sprite_y)
{
	return (player_x = player_y = sprite_x = sprite_y);
}
void draw_sprite_column(int i, cub3d *data)
{
	int y_axis;
	int column_size;
	int max_draw_height;
	int j;
	float distance;

	distance = get_sprite_distance(data->render_data.player_x, data->render_data.player_y, data->ray_trc.sprite_x, data->ray_trc.sprite_y);
	y_axis = data->render_data.res_y / 2;
	column_size = (int)(data->ray_trc.column_height / (2 * distance));
	max_draw_height = column_size > y_axis / 2 ? y_axis / 2 : column_size;
	j = 0;
	while (j < max_draw_height) //Move to a different function, check for sprite in a while to avoid double drawing...
	{
		draw_pixel(data->mlx_data.background, i, y_axis + j, add_shade(get_sprite_colour(data, column_size, j), distance));
		draw_pixel(data->mlx_data.background, i, y_axis - j, add_shade(get_sprite_colour(data, column_size, -j), distance));
		j++;
	}
}
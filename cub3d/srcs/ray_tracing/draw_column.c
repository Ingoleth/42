/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:57:41 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/17 00:02:52 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data		*get_texture_to_render(int index, s_render_data *render_data)
{
	if (index == NORTH)
		return (&render_data->north_texture);
	else if (index == WEST)
		return (&render_data->west_texture);
	else if (index == SOUTH)
		return (&render_data->south_texture);
	else
		return (&render_data->east_texture);
}

unsigned	get_image_colour(cub3d *data, int column_size, int img_y)
{
	t_data	*image;
	int		x;
	int		y;

	image = get_texture_to_render(data->ray_trc.cardinal_collision,
	&data->render_data);
	y = (int)(image->height * img_y / (float)column_size);
	x = image->width * data->ray_trc.img_x;
	return (get_pixel(image, x, y));
}

void		draw_column(int i, float distance, cub3d *data, int y_offset)
{
	int	column_size;
	int	starting_position;
	int	j;

	column_size = (int)(data->render_data.column_height / (distance));
	starting_position = data->render_data.res_y / 2 - column_size / 2
	+ y_offset;
	j = starting_position < 0 ? -starting_position : 0;
	if (data->ray_trc.cardinal_collision == NORTH ||
		data->ray_trc.cardinal_collision == SOUTH)
			data->ray_trc.img_x = data->ray_trc.x_collision
			- (int)data->ray_trc.x_collision;
		else
			data->ray_trc.img_x = data->ray_trc.y_collision
			- (int)data->ray_trc.y_collision;
	while (j++ < column_size && starting_position + j < data->render_data.res_y)
		draw_pixel(data->mlx_data.background, i, starting_position + j,
		get_image_colour(data, column_size, j));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:18:34 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/10 13:20:13 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

s_coords	set_draw_coords(int x, int y, int end_x, int end_y)
{
	s_coords coords;

	coords.x = x;
	coords.y = y;
	coords.end_x = end_x;
	coords.end_y = end_y;
	return (coords);
}

unsigned	get_pixel(t_data *image, int x, int y)
{
	return (*((unsigned int*)(image->addr +
	(y * image->line_length + x * (image->bits_per_pixel / 8)))));
}

void		draw_pixel(t_data *image, int x, int y, int color)
{
	*(unsigned int*)(image->addr + (y * image->line_length + x
	* (image->bits_per_pixel / 8))) = color;
}

void		draw_pixel_area(t_data *image, s_coords coords, int color)
{
	int aux;

	aux = coords.x;
	while (coords.y < coords.end_y)
	{
		while (coords.x < coords.end_x)
		{
			draw_pixel(image, coords.x, coords.y, color);
			coords.x++;
		}
		coords.y++;
		coords.x = aux;
	}
}

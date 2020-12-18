/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_render.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:29:10 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/17 00:02:52 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map_corner(t_data *map_image, int border_start,
float border_side, t_data *corner)
{
	int i;
	int j;
	int border_end;

	border_end = border_start + border_side;
	i = border_start;
	j = border_start;
	while (i < border_end)
	{
		while (j < border_end)
		{
			draw_pixel(map_image, i, j, get_pixel(corner, 7 + (i - border_start)
			/ border_side * 7, 7 + (j - border_start) / border_side * 7));
			j++;
		}
		i++;
		j = border_start;
	}
}

void	draw_lower_side(int border_start, float border_side,
t_data *map_image, t_data *corner)
{
	int i;
	int j;
	int border_end;

	border_end = border_start + border_side;
	i = border_start;
	j = 0;
	while (j < border_start)
	{
		while (i < border_end)
		{
			draw_pixel(map_image, i, j, get_pixel(corner, 7 +
			(i - border_start) / border_side * 7, 0));
			i++;
		}
		i = border_start;
		j++;
	}
}

void	draw_map_sides(t_data *map_image, int border_start,
float border_side, t_data *corner)
{
	int i;
	int j;
	int border_end;

	border_end = border_start + border_side;
	i = 0;
	j = border_start;
	while (i < border_start)
	{
		while (j < border_end)
		{
			draw_pixel(map_image, i, j, get_pixel(corner, 0, 7 +
			(j - border_start) / border_side * 7));
			j++;
		}
		j = border_start;
		i++;
	}
	draw_lower_side(border_start, border_side, map_image, corner);
}

void	draw_edges(t_data *map_image, int border_start, int border_side,
void *mlx_ptr)
{
	t_data *corner;

	corner = load_xpm_image(mlx_ptr,
	"/home/user42/Documents/42/cub3d/textures/map_edges.xpm");
	draw_map_sides(map_image, border_start, border_side, corner);
	draw_map_corner(map_image, border_start, border_side, corner);
	free_image(mlx_ptr, corner);
}

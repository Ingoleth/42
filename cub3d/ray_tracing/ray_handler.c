/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:26:03 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/10 12:24:41 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** If the opposing coordinate increases, do 1 - offset!
*/

int	calculate_collision_0(float p_x, float p_y, s_ray_tracing *ray_trc,
char **map)
{
	int x;
	int y;

	x = (int)p_x;
	y = (int)p_y;
	ray_trc->x_collision = p_x + (p_y - y) * ray_trc->tan_x;
	ray_trc->y_collision = p_y - (1 - p_x + x) * ray_trc->tan_y;
	while (x)
	{
		while (ray_trc->x_collision - x <= 1 + y - ray_trc->y_collision)
		{
			y--;
			if (check_wall_collision(map[y][x], y + 1, ray_trc, true))
				return (ray_trc->cardinal_collision = SOUTH);
			ray_trc->x_collision += ray_trc->tan_x;
		}
		while (ray_trc->x_collision - x > 1 + y - ray_trc->y_collision)
		{
			x++;
			if (check_wall_collision(map[y][x], x, ray_trc, false))
				return (ray_trc->cardinal_collision = WEST);
			ray_trc->y_collision -= ray_trc->tan_y;
		}
	}
	return (0);
}

int	calculate_collision_1(float p_x, float p_y, s_ray_tracing *ray_trc,
char **map)
{
	int x;
	int y;

	x = (int)p_x;
	y = (int)p_y;
	ray_trc->x_collision = p_x - (p_y - y) * ray_trc->tan_x;
	ray_trc->y_collision = p_y - (p_x - x) * ray_trc->tan_y;
	while (x)
	{
		while (1 + x - ray_trc->x_collision <= 1 + y - ray_trc->y_collision)
		{
			y--;
			if (check_wall_collision(map[y][x], y + 1, ray_trc, true))
				return (ray_trc->cardinal_collision = SOUTH);
			ray_trc->x_collision -= ray_trc->tan_x;
		}
		while (1 + x - ray_trc->x_collision > 1 + y - ray_trc->y_collision)
		{
			x--;
			if (check_wall_collision(map[y][x], x + 1, ray_trc, false))
				return (ray_trc->cardinal_collision = EAST);
			ray_trc->y_collision -= ray_trc->tan_y;
		}
	}
	return (0);
}

int	calculate_collision_2(float p_x, float p_y, s_ray_tracing *ray_trc,
char **map)
{
	int x;
	int y;

	x = (int)p_x;
	y = (int)p_y;
	ray_trc->x_collision = p_x - (1 - p_y + y) * ray_trc->tan_x;
	ray_trc->y_collision = p_y + (p_x - x) * ray_trc->tan_y;
	while (x)
	{
		while (1 + x - ray_trc->x_collision <= ray_trc->y_collision - y)
		{
			y++;
			if (check_wall_collision(map[y][x], y, ray_trc, true))
				return (ray_trc->cardinal_collision = NORTH);
			ray_trc->x_collision -= ray_trc->tan_x;
		}
		while (1 + x - ray_trc->x_collision > ray_trc->y_collision - y)
		{
			x--;
			if (check_wall_collision(map[y][x], x + 1, ray_trc, false))
				return (ray_trc->cardinal_collision = EAST);
			ray_trc->y_collision += ray_trc->tan_y;
		}
	}
	return (0);
}

int	calculate_collision_3(float p_x, float p_y, s_ray_tracing *ray_trc,
char **map)
{
	int x;
	int y;

	x = (int)p_x;
	y = (int)p_y;
	ray_trc->x_collision = p_x + (1 - p_y + y) * ray_trc->tan_x;
	ray_trc->y_collision = p_y + (1 - p_x + x) * ray_trc->tan_y;
	while (x)
	{
		while (ray_trc->x_collision - x <= ray_trc->y_collision - y)
		{
			y++;
			if (check_wall_collision(map[y][x], y, ray_trc, true))
				return (ray_trc->cardinal_collision = NORTH);
			ray_trc->x_collision += ray_trc->tan_x;
		}
		while (ray_trc->x_collision - x > ray_trc->y_collision - y)
		{
			x++;
			if (check_wall_collision(map[y][x], x, ray_trc, false))
				return (ray_trc->cardinal_collision = WEST);
			ray_trc->y_collision += ray_trc->tan_y;
		}
	}
	return (0);
}

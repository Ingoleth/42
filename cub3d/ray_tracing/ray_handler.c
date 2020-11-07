/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:26:03 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/07 09:16:13 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** If the opposing coordinate increases, do 1 - offset!
*/

int calculate_collision_0(float *x, float *y, s_ray_tracing *ray_trc, char **map)
{
	float tan_x;
	float tan_y;

	tan_y = handle_tan(ray_trc->angle);
	tan_x = ray_trc->angle ? 1 / tan_y : 60;
	ray_trc->x_collision = *x + (*y - (int)*y) * tan_x;
	ray_trc->y_collision = *y - (1 - *x + (int)*x) * tan_y;
	*x = (int)*x;
	*y = (int)*y;
	while (x)
	{
		while (ray_trc->x_collision < *x + 1)
		{
			(*y)--;
			ray_trc->x_collision += tan_x;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = SOUTH) && (ray_trc->y_collision = *y + 1));
		}
		while (ray_trc->y_collision > *y)
		{
			(*x)++;
			ray_trc->y_collision -= tan_y;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = WEST) && (ray_trc->x_collision = *x + 1));
		}
	}
	return(0);
}

int calculate_collision_1(float *x, float *y, s_ray_tracing *ray_trc, char **map)
{
	float tan_x;
	float tan_y;

	tan_y = -handle_tan(ray_trc->angle);
	tan_x = 1 / tan_y;
	ray_trc->x_collision = *x - (*y - (int)*y) * tan_x;
	ray_trc->y_collision = *y - (*x - (int)*x) * tan_y;
	*x = (int)*x;
	*y = (int)*y;
	while (x)
	{
		while (ray_trc->x_collision > *x)
		{
			(*y)--;
			ray_trc->x_collision -= tan_x;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = SOUTH) && (ray_trc->y_collision = *y + 1));
		}
		while (ray_trc->y_collision > *y)
		{
			(*x)--;
			ray_trc->y_collision -= tan_y;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = EAST) && (ray_trc->x_collision = *x - 1));
		}
	}
	return(0);
}

int calculate_collision_2(float *x, float *y, s_ray_tracing *ray_trc, char **map)
{
	float tan_x;
	float tan_y;

	tan_y = handle_tan(ray_trc->angle);
	tan_x = 1 / tan_y;
	ray_trc->x_collision = *x - (1 - *x + (int)*x) * tan_x;
	ray_trc->y_collision = *y + (*x - (int)*x) * tan_y;
	*x = (int)*x;
	*y = (int)*y;
	while (x)
	{
		while (ray_trc->x_collision > *x)
		{
			(*y)++;
			ray_trc->x_collision -= tan_x;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = NORTH) && (ray_trc->y_collision = *y - 1));
		}
		while (ray_trc->y_collision < *y + 1)
		{
			(*x)--;
			ray_trc->y_collision += tan_y;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = EAST) && (ray_trc->x_collision = *x - 1));
		}
	}
	return(0);
}

int calculate_collision_3(float *x, float *y, s_ray_tracing *ray_trc, char **map)
{
	float tan_x;
	float tan_y;

	tan_y = -handle_tan(ray_trc->angle);
	tan_x = 1 / tan_y;
	ray_trc->x_collision = *x + (1 - *y + (int)*y) * tan_x;
	ray_trc->y_collision = *y + (1 - *x + (int)*x) * tan_y;
	*x = (int)*x;
	*y = (int)*y;
	while (x)
	{
		while (ray_trc->x_collision < *x + 1)
		{
			(*y)++;
			ray_trc->x_collision += tan_x;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = NORTH) && (ray_trc->y_collision = *y - 1));
		}
		while (ray_trc->y_collision < *y + 1)
		{
			(*x)++;
			ray_trc->y_collision += tan_y;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = WEST) && (ray_trc->x_collision = *x + 1));
		}
	}
	return(0);
}


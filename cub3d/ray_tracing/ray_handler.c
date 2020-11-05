/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:26:03 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/05 11:32:39 by aiglesia         ###   ########.fr       */
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
	tan_x = 1 / tan_y;
	ray_trc->x_collision = *x + (*y - (int)*y) * tan_x;
	ray_trc->y_collision = *y - (1 - *x + (int)*x) * tan_y;
	*x = (int)*x;
	*y = (int)*y;
	printf("Angle = %f, x = %f, y = %f, x_collision = %f, y_collision = %f;\nTan_x = %f, Tan_y = %f\n", ray_trc->angle, *x, *y, ray_trc->x_collision, ray_trc->y_collision, tan_x, tan_y);
	while (x)
	{
		while (ray_trc->x_collision < *x + 1)
		{
			if(map[(int)*y][(int)*x] == '1')
				return(ray_trc->cardinal_collision = NORTH);
			(*y)--;
			ray_trc->x_collision += tan_x;
		}
		while (ray_trc->y_collision > *y)
		{
			if(map[(int)*y][(int)*x] == '1')
				return(ray_trc->cardinal_collision = EAST);
			(*x)++;
			ray_trc->y_collision -= tan_y;
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
			if(map[(int)*y][(int)*x] == '1')
				return(ray_trc->cardinal_collision = NORTH);
			(*y)--;
			ray_trc->x_collision -= tan_x;
		}
		while (ray_trc->y_collision > *y)
		{
			if(map[(int)*y][(int)*x] == '1')
				return(ray_trc->cardinal_collision = EAST);
			(*x)--;
			ray_trc->y_collision -= tan_y;
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
			if(map[(int)*y][(int)*x] == '1')
				return(ray_trc->cardinal_collision = NORTH);
			(*y)++;
			ray_trc->x_collision -= tan_x;
		}
		while (ray_trc->y_collision < *y + 1)
		{
			if(map[(int)*y][(int)*x] == '1')
				return(ray_trc->cardinal_collision = EAST);
			(*x)--;
			ray_trc->y_collision += tan_y;
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
			if(map[(int)*y][(int)*x] == '1')
				return(ray_trc->cardinal_collision = NORTH);
			(*y)++;
			ray_trc->x_collision += tan_x;
		}
		while (ray_trc->y_collision < *y + 1)
		{
			if(map[(int)*y][(int)*x] == '1')
				return(ray_trc->cardinal_collision = EAST);
			(*x)++;
			ray_trc->y_collision += tan_y;
		}
	}
	return(0);
}


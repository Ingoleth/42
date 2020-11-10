/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:26:03 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/10 19:10:52 by aiglesia         ###   ########.fr       */
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
	float time = (double)clock()/CLOCKS_PER_SEC;
	while (x)
	{
		while (ray_trc->x_collision <= *x + 1)
		{
			(*y)--;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = SOUTH) && (ray_trc->y_collision = *y + 1));
			ray_trc->x_collision += tan_x;
		}
		while (ray_trc->y_collision >= *y)
		{
			(*x)++;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = WEST) && (ray_trc->x_collision = *x));
			ray_trc->y_collision -= tan_y;
		}
	}
	if((double)clock()/CLOCKS_PER_SEC - time > 1)
		return(printf("X = %f, xIntercept = %f; y = %f, yIntercept = %f; Angle = %f Sector = %i Tan = %f\n", *x, ray_trc->x_collision, *y, ray_trc->y_collision, ray_trc->angle, ray_trc->sector, tan_y));
	return(0);
}

int calculate_collision_1(float *x, float *y, s_ray_tracing *ray_trc, char **map)
{
	float tan_x;
	float tan_y;

	tan_y = handle_tan(ray_trc->angle);
	tan_x = 1 / tan_y;
	ray_trc->x_collision = *x - (*y - (int)*y) * tan_x;
	ray_trc->y_collision = *y - (*x - (int)*x) * tan_y;
	*x = (int)*x;
	*y = (int)*y;
	float time = (double)clock()/CLOCKS_PER_SEC;
	while (x)
	{
		while (ray_trc->x_collision >= *x)
		{
			(*y)--;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = SOUTH) && (ray_trc->y_collision = *y + 1));
			ray_trc->x_collision -= tan_x;
		}
		while (ray_trc->y_collision >= *y)
		{
			(*x)--;
			if(map[(int)*y][(int)*x] == '1')
				return((!(ray_trc->cardinal_collision = EAST)) && (ray_trc->x_collision = *x + 1));
			ray_trc->y_collision -= tan_y;
		}
		if((double)clock()/CLOCKS_PER_SEC - time > 1)
			return(printf("X = %f, xIntercept = %f; y = %f, yIntercept = %f; Angle = %f Sector = %i Tan = %f\n", *x, ray_trc->x_collision, *y, ray_trc->y_collision, ray_trc->angle, ray_trc->sector, tan_y));
	}
	return(0);
}

int calculate_collision_2(float *x, float *y, s_ray_tracing *ray_trc, char **map)
{
	float tan_x;
	float tan_y;

	tan_y = handle_tan(ray_trc->angle);
	tan_x = 1 / tan_y;
	ray_trc->x_collision = *x - (1 - *y + (int)*y) * tan_x;
	ray_trc->y_collision = *y + (*x - (int)*x) * tan_y;
	*x = (int)*x;
	*y = (int)*y;
	float time = (double)clock()/CLOCKS_PER_SEC;
	while (x)
	{
		while (ray_trc->x_collision >= *x)
		{
			(*y)++;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = NORTH) && (ray_trc->y_collision = *y));
			ray_trc->x_collision -= tan_x;
		}
		while (ray_trc->y_collision <= *y + 1)
		{
			(*x)--;
			if(map[(int)*y][(int)*x] == '1')
				return((!(ray_trc->cardinal_collision = EAST)) && (ray_trc->x_collision = *x + 1));
			ray_trc->y_collision += tan_y;
		}
		if((double)clock()/CLOCKS_PER_SEC - time > 1)
			return(printf("X = %f, xIntercept = %f; y = %f, yIntercept = %f; Angle = %f Sector: %i Tan = %f\n", *x, ray_trc->x_collision, *y, ray_trc->y_collision, ray_trc->angle, ray_trc->sector, tan_y));
	}
	return(0);
}

int calculate_collision_3(float *x, float *y, s_ray_tracing *ray_trc, char **map)
{
	float tan_x;
	float tan_y;

	tan_y = handle_tan(ray_trc->angle);
	tan_x = 1 / tan_y;
	ray_trc->x_collision = *x + (1 - *y + (int)*y) * tan_x;
	ray_trc->y_collision = *y + (1 - *x + (int)*x) * tan_y;
	*x = (int)*x;
	*y = (int)*y;
		float time = (double)clock()/CLOCKS_PER_SEC;
	while (x)
	{
		while (ray_trc->x_collision <= *x + 1)
		{
			(*y)++;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = NORTH) && (ray_trc->y_collision = *y));
			ray_trc->x_collision += tan_x;
		}
		while (ray_trc->y_collision <= *y + 1)
		{
			(*x)++;
			if(map[(int)*y][(int)*x] == '1')
				return((ray_trc->cardinal_collision = WEST) && (ray_trc->x_collision = *x));
			ray_trc->y_collision += tan_y;
		}
		if((double)clock()/CLOCKS_PER_SEC - time > 1)
			return(printf("X = %f, xIntercept = %f; y = %f, yIntercept = %f; Angle = %f Sector: %i Tan = %f\n", *x, ray_trc->x_collision, *y, ray_trc->y_collision, ray_trc->angle, ray_trc->sector, tan_y));
	}
	return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:00:56 by user42            #+#    #+#             */
/*   Updated: 2020/12/18 12:36:53 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	rad_to_degrees(float angle)
{
	return (angle * 180 / PI);
}

int		get_sector(float angle)
{
	if (angle < PI_2)
		return (0);
	else if (angle < PI)
		return (1);
	else if (angle < PI1_1_2)
		return (2);
	else
		return (3);
}

float	handle_tan(float angle)
{
	float tang;

	if (angle == 0 || angle == PI)
		tang = 0.01;
	else if (angle == PI_2 || angle == PI1_1_2)
		tang = 60;
	else
		tang = fabs(tan(angle));
	if (tang > 0.999 && fabsf(tang) < 1.001)
		tang = 1.001;
	return (tang);
}

void	update_angle_info(t_keys *keys, float *angle)
{
	static float ang = 0;

	if (!ang)
		ang = ANGLE_1 * ROTATION_SPEED;
	if (keys->right)
	{
		*angle -= ang;
		if (*angle < 0)
			*angle = PI2 + *angle;
	}
	if (keys->left)
	{
		*angle += ang;
		if (*angle >= PI2)
			*angle = *angle - PI2;
	}
}

void	update_ver_angle_info(t_keys *keys, float *angle)
{
	static float ang = 0;

	if (!ang)
		ang = ANGLE_1 * VER_ROTATION_SPEED;
	if (keys->up)
	{
		if (*angle < 0.5)
			*angle += ang;
	}
	if (keys->down)
	{
		if (*angle > -0.5)
			*angle -= ang;
	}
	if (keys->down && keys->up)
		*angle = 0;
}

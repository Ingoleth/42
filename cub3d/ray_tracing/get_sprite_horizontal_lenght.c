/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_horizontal_lenght.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:09:21 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/14 19:27:20 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float get_sprite_lenght_0(s_ray_tracing *ray_trc, float view_angle)
{
	float sprite_lenght;

	if (ray_trc->sprite > 0)
		sprite_lenght = fabs(cos(view_angle) * (ray_trc->sprite_x - (int)ray_trc->sprite_x));
	else
		sprite_lenght = fabs(fabs(cos(view_angle)) + fabs(sin(view_angle) * (1 + (int)ray_trc->sprite_y - ray_trc->sprite_y)));
	return (sprite_lenght);
}

float get_sprite_lenght_1(s_ray_tracing *ray_trc, float view_angle)
{
	float sprite_lenght;

	if (ray_trc->sprite > 0)
		sprite_lenght = fabs(fabs(cos(view_angle) * (1 + (int)ray_trc->sprite_x - ray_trc->sprite_x)) + fabs(sin(view_angle)));
	else
		sprite_lenght = fabs(sin(view_angle) * (1 + (int)ray_trc->sprite_y - ray_trc->sprite_y));
	return (sprite_lenght);
}

float	get_sprite_horizontal_lenght(s_ray_tracing *ray_trc, float view_angle)
{
	float sprite_lenght;

	return(0);
	if (ray_trc->sector == 0)
		sprite_lenght = get_sprite_lenght_0(ray_trc, view_angle);
	else //if (ray_trc->sector == 1)
		sprite_lenght = get_sprite_lenght_1(ray_trc, view_angle);
	return(sprite_lenght);
}
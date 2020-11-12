/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:06:53 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/12 14:51:25 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_bool check_sprite_collision(int x, int y, char **map, s_ray_tracing * ray_trc)
{
	if(map[y][x] == '1')
		return (true);
	ray_trc++;
	return (0);
}

void draw_sprite(int i, int j, cub3d *data)
{
	i = j + (int)data;
	printf("Im done with the sprite!\n");
}
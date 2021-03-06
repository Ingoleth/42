/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:06:53 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/20 11:49:26 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_sprite(t_ray_tracing *ray_trc, int tile_value, float x, float y)
{
	t_sprite	*sprite;
	t_list		*sprite_ptr;

	sprite_ptr = ray_trc->sprite;
	while (sprite_ptr)
	{
		sprite = (t_sprite *)sprite_ptr->content;
		if (sprite->sprite_x == x && sprite->sprite_y == y)
			return ;
		sprite_ptr = sprite_ptr->next;
	}
	if (!(sprite = ft_calloc(1, sizeof(t_sprite))))
		return ;
	sprite->sprite_x = x;
	sprite->sprite_y = y;
	sprite->texture = tile_value;
	ft_lstadd_front(&ray_trc->sprite, ft_lstnew(sprite));
}

void	order_sprites(t_list *sprite)
{
	t_list	*aux;
	int		i;

	i = 1;
	while (i)
	{
		i = 0;
		aux = sprite;
		if (aux->next)
			while (aux)
			{
				if (aux->next && ((t_sprite *)aux->next->content)->distance >
				((t_sprite *)aux->content)->distance)
				{
					i = 1;
					ft_lstmove_backwards(aux);
				}
				aux = aux->next;
			}
	}
}

void	check_tile_collision(int tile_value, int tile_coord,
t_ray_tracing *ray_trc, t_bool horiz)
{
	float x;
	float y;

	if (tile_value > '1')
	{
		if (horiz)
		{
			x = (int)ray_trc->x_collision + 0.5;
			y = tile_coord +
			(ray_trc->sector == 0 || ray_trc->sector == 1 ? -1 : 0) + 0.5;
		}
		else
		{
			x = tile_coord +
			(ray_trc->sector == 1 || ray_trc->sector == 2 ? -1 : 0) + 0.5;
			y = (int)ray_trc->y_collision + 0.5;
		}
		add_sprite(ray_trc, tile_value, x, y);
	}
}

t_bool	check_wall_collision(int tile_value, int tile_coord,
t_ray_tracing *ray_trc, t_bool horiz)
{
	if (tile_value == '1')
	{
		if (horiz)
			ray_trc->y_collision = tile_coord;
		else
			ray_trc->x_collision = tile_coord;
		return (true);
	}
	check_tile_collision(tile_value, tile_coord, ray_trc, horiz);
	return (false);
}

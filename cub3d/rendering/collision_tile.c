/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_tile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:37:13 by user42            #+#    #+#             */
/*   Updated: 2020/11/02 12:19:18 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void 	add_collision_tile(t_collision **ptr, int x, int y)
{
	t_collision *str;
	if (!*ptr)
	{
		if(!(*ptr = ft_calloc(1, sizeof(t_collision))))
			return ;
		(*ptr)->x = x;
		(*ptr)->y = y;
		(*ptr)->not_dirty = true;
	}
	else
	{
		str = *ptr;
		while ((x != str->x || y != str->y) && str->next)
			str = str->next;
		if (str->x == x && str->y == y)
			str->not_dirty = true;
		else
		{
			if(!(str->next = ft_calloc(1, sizeof(t_collision))))
				return ;
			str->next->x = x;
			str->next->y = y;
			str->next->not_dirty = true;
		}
	}
}

void 	free_collision_tile(t_collision **str)
{
	if (*str)
	{
		if ((*str)->next)
			free_collision_tile(&(*str)->next);
		free (*str);
	}
	*str = 0;
}

void 	render_collision_tile(t_collision *str, s_mlx *mlx_data)
{
	s_coords coords;
	int line_size;
	int x;
	int y;

	line_size = mlx_data->tile_size / LINE_WIDTH;
    while (str)
	{
		x = str->x * mlx_data->tile_size;
		y = str->y * mlx_data->tile_size;
		coords = set_draw_coords(x + line_size, y + line_size, x +
		mlx_data->tile_size - line_size, y + mlx_data->tile_size - line_size);
		printf("x = %i, y = %i\n", str->x, str->y);
		draw_pixel_area(mlx_data->map, coords, str->not_dirty ? RED : WHITE);
		str = str->next;
	}
	printf("---\n");
}

void	remove_collision_tile(t_collision **str, t_collision **aux)
{
	if(*str == *aux)
	{
		(*str) = (*str)->next;
		free(*aux);
		*aux = *str;
	}
	else
	{
		while ((*str)->next != *aux)
			*str = (*str)->next;
		(*str)->next = (*aux)->next;
		free(*aux);
		(*aux) = (*str)->next;
		
	}
}

void	clean_collision_tiles(t_collision **str, s_mlx *mlx_data)
{
	t_collision *aux;

	aux = *str;
	while (aux)
	{
		if(aux->not_dirty)
		{
			aux->not_dirty = false;
			aux = aux->next;
		}
		else
			remove_collision_tile(str, &aux);
	}
	render_collision_tile(*str, mlx_data);
}
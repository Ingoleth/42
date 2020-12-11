/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:17:49 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/11 12:45:30 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		get_tile_size(char **map, int side_size, s_map_render *map_render)
{
	int		i;
	int		j;
	float	tile_size;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	while (map[i])
	{
		while (map[i][j])
			j++;
		if (x < j)
			x = j;
		i++;
		j = 0;
	}
	tile_size = side_size / (i > x ? i : x);
	tile_size = tile_size > TILE_MAXIMUM ? TILE_MAXIMUM : tile_size;
	map_render->size_x = x * tile_size;
	map_render->size_y = i * tile_size;
	return (tile_size);
}

void	draw_actual_tiles(t_data *map_img, s_map_render *map_render, int x,
int y)
{
	unsigned	colour;
	int			current_tile;

	current_tile = map_render->current_tile;
	if (current_tile == '1')
		colour = WHITE;
	else if (current_tile == '0')
		colour = GREY;
	else if (current_tile == '1')
		colour = RED;
	else if (current_tile == '2')
		colour = YELLOW;
	else if (current_tile == '3')
		colour = PURPLE;
	draw_pixel_area(map_img, set_draw_coords(x, y, x + map_render->tile_size -
	map_render->line_size, y + map_render->tile_size - map_render->line_size),
	colour);
}

void	draw_tiles(t_data *map_img, s_map_render *map_render,
int initial_x, int initial_y)
{
	int		i;
	int		j;
	char	**map;

	map = map_render->map;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j++])
		{
			if (map[i][j] != ' ')
			{
				map_render->current_tile = map[i][j];
				draw_actual_tiles(map_img, map_render, j * map_render->tile_size
				+ map_render->line_size + initial_x, i * map_render->tile_size
				+ map_render->line_size + initial_y);
			}
		}
		i++;
		j = 0;
	}
}

void	load_map(char **map, s_mlx *mlx_data, int res_x, int res_y)
{
	int				map_size;
	int				border_size;
	s_map_render	map_render;

	map_size = res_x < res_y ? res_x / MAP_RATIO : res_y / MAP_RATIO;
	map_size = map_size == 0 ? 1 : map_size;
	border_size = map_size / BORDER_RATIO;
	map_render.map = map;
	map_render.tile_size = get_tile_size(map, map_size - border_size,
	&map_render);
	map_render.line_size = map_render.tile_size / LINE_WIDTH;
	map_render.line_size = map_render.line_size == 0 ? 1 : map_render.line_size;
	mlx_data->tile_size = map_render.tile_size;
	mlx_data->map_initial_x = (map_size - border_size - map_render.size_x) / 2;
	mlx_data->map_initial_y = (map_size - border_size - map_render.size_y) / 2;
	mlx_data->map = initialize_image(mlx_data->mlx_ptr, map_size, map_size);
	draw_tiles(mlx_data->map, &map_render,
	mlx_data->map_initial_x, mlx_data->map_initial_y);
	draw_edges(mlx_data->map, map_size - border_size,
	border_size, mlx_data->mlx_ptr);
}

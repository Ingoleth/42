/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:33:22 by user42            #+#    #+#             */
/*   Updated: 2020/11/09 12:44:22 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int    get_tile_size(char **map, int side_size, int *x, int *y)
{
    int i;
    int j;

    i = 0;
    j = 0;
    *x = 0;
    while (map[i])
    {
        while (map[i][j])
            j++;
        if (*x < j)
            *x = j;
        i++;
        j = 0;
    }
    *y = i < TILE_MINIMUM ? TILE_MINIMUM : i;
    *x = *x < TILE_MINIMUM ? TILE_MINIMUM : *x;
    return((side_size / MAP_RATIO) / (*y > *x ? *y : *x));
}

void draw_tiles(t_data *map_img, char **map, int tile_size, int line_size)
{
    int x;
    int y;
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        while (map[i][j])
        {
            if (map[i][j] == ' ')
                j++;
            else
            {
                x = j * tile_size + line_size;
                y = i * tile_size + line_size;
                draw_pixel_area(map_img, set_draw_coords(x, y, x + tile_size - line_size, y + tile_size - line_size), map[i][j] == '1' ? WHITE : GREY);
                j++;
            }
        }
        i++;
        j = 0;
    }
}

void    load_map(char **map, s_mlx *mlx_data, int res_x, int res_y)
{
    int tile_size;
       
    tile_size = get_tile_size(map, res_x < res_y ? res_x : res_y, &res_x, &res_y);
	mlx_data->tile_size = tile_size;
    mlx_data->map = initialize_image(mlx_data->mlx_ptr, res_x * tile_size, res_y *tile_size);
    draw_tiles(mlx_data->map, map, tile_size, tile_size / LINE_WIDTH);
}

s_render_data *initialize_render_data(s_mlx *mlx_data, cub3d *data)
{
    s_render_data *render_data;

    if (!(render_data = read_file("/home/user42/Documents/42_2/cub3d/map")) ||
	check_render_data(render_data, mlx_data->mlx_ptr))
		return (free_render_data(render_data));
    mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, render_data->res_x, render_data->res_y, "Cub3d");
	load_floor_ceiling(render_data, mlx_data);
	load_map(render_data->map, mlx_data, render_data->res_x, render_data->res_y);
    load_cursor(mlx_data, render_data->view_angle);
    data->render_data = render_data;
    data->ray_trc.column_height = render_data->res_y / 6;
    ft_memset(&data->mlx_data.keys_pressed, 0, sizeof(t_keys));
    redraw_screen(data);
    return(render_data);
}

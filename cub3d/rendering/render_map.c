/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:45:57 by user42            #+#    #+#             */
/*   Updated: 2020/10/08 12:08:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

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

void    render_map(char **map, s_mlx *mlx_data, int res_x, int res_y)
{
    int tile_size;
       

    tile_size = get_tile_size(map, res_x < res_y ? res_x : res_y, &res_x, &res_y);
    mlx_data->map = initialize_image(mlx_data->mlx_ptr, res_x * tile_size, res_y *tile_size);
    //draw_pixel_area(mlx_data->map, set_draw_coords(0, 0, res_x * tile_size, res_y * tile_size), BLACK);
    draw_tiles(mlx_data->map, map, tile_size, tile_size / LINE_WIDTH);
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->map->img, 0, 0);
    load_cursor(mlx_data);
    //initialize_xpm_image(mlx_data->mlx_ptr, "./textures/cursor/cursor_north.xpm");
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->cursor.north, 31 * tile_size + 4, 4 *tile_size + 2);
}
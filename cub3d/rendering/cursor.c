/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 09:35:38 by user42            #+#    #+#             */
/*   Updated: 2020/10/08 14:10:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int load_cursor(s_mlx *mlx_data) //Should probably check if image...
{
    if (!(mlx_data->cursor = ft_calloc(9, sizeof(t_data))))
        return (0);
    mlx_data->cursor[0] = load_xpm_image(mlx_data->mlx_ptr, CURSOR_NORTH);
    mlx_data->cursor[1] = load_xpm_image(mlx_data->mlx_ptr, CURSOR_NORTH_EAST);
    mlx_data->cursor[2] = load_xpm_image(mlx_data->mlx_ptr, CURSOR_EAST);
    mlx_data->cursor[3] = load_xpm_image(mlx_data->mlx_ptr, CURSOR_SOUTH_EAST);
    mlx_data->cursor[4] = load_xpm_image(mlx_data->mlx_ptr, CURSOR_SOUTH);
    mlx_data->cursor[5] = load_xpm_image(mlx_data->mlx_ptr, CURSOR_SOUTH_WEST);
    mlx_data->cursor[6] = load_xpm_image(mlx_data->mlx_ptr, CURSOR_WEST);
    mlx_data->cursor[7] = load_xpm_image(mlx_data->mlx_ptr, CURSOR_NORTH_WEST);
    return (0);
}

void render_cursor(s_mlx *mlx_data, s_render_data *render_data)
{
    int x;
    int y;
    float angle;
    t_data    *image;

    image = mlx_data->cursor[mlx_data->current_cursor];
    x = render_data->player_x * mlx_data->tile_size + render_data->offset_x;
    x = render_data->player_x * mlx_data->tile_size + render_data->offset_x;
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, image->img, x, y);
}
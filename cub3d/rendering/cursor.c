/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 09:35:38 by user42            #+#    #+#             */
/*   Updated: 2020/10/10 14:39:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int set_cursor(float angle)
{
    if (angle > PI1_7_8 || angle < PI_8)
        return(0);
    if (angle >= PI_8 && angle < PI3_8)
        return(1);
    if (angle >= PI3_8 && angle < PI5_8)
        return(2);
    if (angle >= PI5_8 && angle < PI7_8)
        return(3);
    if (angle >= PI7_8 && angle < PI1_1_8)
        return(4);
    if (angle >= PI1_1_8 && angle < PI1_3_8)
        return(5);
    if (angle >= PI1_3_8 && angle < PI1_5_8)
        return(6);
    else
        return(7);
}

int load_cursor(s_mlx *mlx_data, float angle) //Should probably check if image... Check for errrors!
{
    if (!(mlx_data->cursor = ft_calloc(9, sizeof(t_data))))
        return (0);
    mlx_data->current_cursor = set_cursor(angle);
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
    mlx_data->current_cursor = set_cursor(render_data->view_angle);
    image = mlx_data->cursor[mlx_data->current_cursor];
    angle = render_data->view_angle;
    x = render_data->player_x * mlx_data->tile_size + render_data->offset_x * (mlx_data->tile_size / MAX_OFFSET);
    y = render_data->player_y * mlx_data->tile_size + render_data->offset_y * (mlx_data->tile_size / MAX_OFFSET);
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, image->img, x, y);
}
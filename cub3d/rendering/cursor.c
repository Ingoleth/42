/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 09:35:38 by user42            #+#    #+#             */
/*   Updated: 2020/10/08 12:13:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int load_cursor(s_mlx *mlx_data) //Should probably check if image...
{
    mlx_data->cursor.north = load_xpm_image(mlx_data->mlx_ptr, CURSOR_NORTH);
    mlx_data->cursor.north_west = load_xpm_image(mlx_data->mlx_ptr,
    CURSOR_NORTH_EAST);
    mlx_data->cursor.south = load_xpm_image(mlx_data->mlx_ptr, CURSOR_EAST);
    mlx_data->cursor.south_east = load_xpm_image(mlx_data->mlx_ptr,
    CURSOR_SOUTH_EAST);
    mlx_data->cursor.south = load_xpm_image(mlx_data->mlx_ptr, CURSOR_SOUTH);
    mlx_data->cursor.south_west = load_xpm_image(mlx_data->mlx_ptr,
    CURSOR_SOUTH_WEST);
    mlx_data->cursor.west = load_xpm_image(mlx_data->mlx_ptr, CURSOR_WEST);
    mlx_data->cursor.north_west = load_xpm_image(mlx_data->mlx_ptr,
    CURSOR_NORTH_WEST);
    return (0);
}
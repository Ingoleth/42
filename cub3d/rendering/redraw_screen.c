/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:55:47 by user42            #+#    #+#             */
/*   Updated: 2020/10/08 14:45:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int redraw_screen(cub3d *data)
{
    s_mlx *mlx_data;

    mlx_data = data->mlx_data;
    //mlx_clear_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
      printf("Hello world! mlx_data = %i\n", mlx_data->tile_size);
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->background->img, 0, 0);
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->map->img, 0, 0);
    render_cursor(mlx_data, data->render_data);
    return(0);
}
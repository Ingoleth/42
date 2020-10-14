/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:07:13 by user42            #+#    #+#             */
/*   Updated: 2020/10/14 12:11:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int movement_keys(int keycode)
{
    return((keycode == FORWARD || keycode == BACKWARDS || keycode == STRAFE_LEFT
    || keycode == STRAFE_RIGHT));
}

int handle_keys (int keycode, cub3d *data)
{
	s_mlx *mlx_data;

	mlx_data = &data->mlx_data;
    
    if (movement_keys(keycode))
        handle_movement(keycode, data);
    if (keycode == LOOK_LEFT || keycode == LOOK_RIGHT)
        update_angle_info(keycode, data);
	if (keycode == ESC)
        close_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	redraw_screen(data);
	return(0);
}
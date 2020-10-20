/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:07:13 by user42            #+#    #+#             */
/*   Updated: 2020/10/19 18:27:56 by user42           ###   ########.fr       */
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
    else if (keycode == LOOK_LEFT || keycode == LOOK_RIGHT)
        update_angle_info(keycode, &data->render_data->view_angle);
    else if (keycode == ENTER)
        calculate_collision(data->render_data->view_angle, data->render_data, &data->ray_trc);
	else if (keycode == ESC)
        close_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
    else
        printf("A key has been pressed!\n Keycode = %i\n", keycode); //Remove when done
        redraw_screen(data);
	return(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:07:13 by user42            #+#    #+#             */
/*   Updated: 2020/11/08 17:07:45 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int handle_keys (int keycode, cub3d *data)
{
	s_mlx *mlx_data;

	mlx_data = &data->mlx_data;
    
    if (keycode == FORWARD || keycode == BACKWARDS)
        handle_movement(keycode, data);
    else if (keycode == LOOK_LEFT || keycode == LOOK_RIGHT)
        update_angle_info(keycode, &data->render_data->view_angle);
    else if (keycode == ENTER)
    {
        float distance = calculate_collision(2.356194, data);
        printf("Collision found at: %f, %f. Distance = %f; Collision direction = %i, sector = %i\n", data->ray_trc.x_collision, data->ray_trc.y_collision, distance, data->ray_trc.cardinal_collision, get_sector(data->render_data->view_angle));
    }
	else if (keycode == ESC)
        cleanup(data);
    else
        printf("A key has been pressed!\n Keycode = %i\n Colour image = %u, c_rgb = %u\n", keycode, get_pixel(data->mlx_data.background, 0, 0), data->render_data->c_rgb); //Remove when done
        redraw_screen(data);
	return(0);
}
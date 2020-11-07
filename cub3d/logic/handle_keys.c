/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:07:13 by user42            #+#    #+#             */
/*   Updated: 2020/11/06 09:30:40 by aiglesia         ###   ########.fr       */
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
        ray_trace(data);
	else if (keycode == ESC)
        cleanup(data);
    else
        printf("A key has been pressed!\n Keycode = %i\n", keycode); //Remove when done
        redraw_screen(data);
	return(0);
}
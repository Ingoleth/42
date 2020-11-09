/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:07:13 by user42            #+#    #+#             */
/*   Updated: 2020/11/09 12:30:51 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		on_key_pressed(int keycode, cub3d *data)
{
	if (keycode == FORWARD)
		data->mlx_data.keys_pressed.forward = true;
	if (keycode == BACKWARDS)
		data->mlx_data.keys_pressed.backwards = true;
	if (keycode == LOOK_LEFT)
		data->mlx_data.keys_pressed.left = true;
	if (keycode == LOOK_RIGHT)
		data->mlx_data.keys_pressed.right = true;
    if (keycode == ESC)
        cleanup(data);
    else
        printf("A key has been pressed!\n Keycode = %i\n Colour image = %u, c_rgb = %u\n", keycode, get_pixel(data->mlx_data.background, 0, 0), data->render_data->c_rgb); //Remove when done
	return (0);
}

int		on_key_released(int keycode, s_mlx *mlx_data)
{
	if (keycode == FORWARD)
		mlx_data->keys_pressed.forward = false;
	if (keycode == BACKWARDS)
		mlx_data->keys_pressed.backwards = false;
	if (keycode == LOOK_LEFT)
		mlx_data->keys_pressed.left = false;
	if (keycode == LOOK_RIGHT)
		mlx_data->keys_pressed.right = false;
	return (0);
}

int check_keys (cub3d *data)
{
	s_mlx *mlx_data;

	mlx_data = &data->mlx_data;
    if(data->mlx_data.keys_pressed.forward || data->mlx_data.keys_pressed.backwards || data->mlx_data.keys_pressed.left || data->mlx_data.keys_pressed.right)
    {
        if (data->mlx_data.keys_pressed.forward || data->mlx_data.keys_pressed.backwards)
            handle_movement(data);
        if (data->mlx_data.keys_pressed.left || data->mlx_data.keys_pressed.right)
            update_angle_info(&data->mlx_data.keys_pressed, &data->render_data->view_angle);
        redraw_screen(data);
    }
    return(0);
}
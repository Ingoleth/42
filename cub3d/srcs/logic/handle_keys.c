/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:07:13 by user42            #+#    #+#             */
/*   Updated: 2020/12/20 11:51:07 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_special_keys(t_cub3d *data, int keycode)
{
	if (keycode == ENTER)
	{
		data->mlx_data.keys_pressed.enter = data->mlx_data.keys_pressed.enter ?
		false : true;
		redraw_screen(data);
	}
	if (keycode == ESC)
		cleanup(data);
}

int		on_key_pressed(int keycode, t_cub3d *data)
{
	if (keycode == FORWARD)
		data->mlx_data.keys_pressed.forward = true;
	if (keycode == BACKWARDS)
		data->mlx_data.keys_pressed.backwards = true;
	if (keycode == MOVE_LEFT)
		data->mlx_data.keys_pressed.mv_left = true;
	if (keycode == MOVE_RIGHT)
		data->mlx_data.keys_pressed.mv_right = true;
	if (keycode == LOOK_LEFT)
		data->mlx_data.keys_pressed.left = true;
	if (keycode == LOOK_RIGHT)
		data->mlx_data.keys_pressed.right = true;
	handle_special_keys(data, keycode);
	return (0);
}

int		on_key_released(int keycode, t_mlx *mlx_data)
{
	if (keycode == FORWARD)
		mlx_data->keys_pressed.forward = false;
	if (keycode == BACKWARDS)
		mlx_data->keys_pressed.backwards = false;
	if (keycode == MOVE_LEFT)
		mlx_data->keys_pressed.mv_left = false;
	if (keycode == MOVE_RIGHT)
		mlx_data->keys_pressed.mv_right = false;
	if (keycode == LOOK_LEFT)
		mlx_data->keys_pressed.left = false;
	if (keycode == LOOK_RIGHT)
		mlx_data->keys_pressed.right = false;
	return (0);
}

t_bool	is_key_pressed(t_keys *keys)
{
	if (keys->forward ||
	keys->backwards ||
	keys->mv_left ||
	keys->mv_right ||
	keys->left ||
	keys->right)
		return (true);
	else
		return (false);
}

int		check_keys(t_cub3d *data)
{
	if (is_key_pressed(&data->mlx_data.keys_pressed))
	{
		if (data->mlx_data.keys_pressed.forward ||
		data->mlx_data.keys_pressed.backwards ||
		data->mlx_data.keys_pressed.mv_right ||
		data->mlx_data.keys_pressed.mv_left)
			handle_movement(data);
		if (data->mlx_data.keys_pressed.left ||
		data->mlx_data.keys_pressed.right)
			update_angle_info(&data->mlx_data.keys_pressed,
			&data->render_data.view_angle);
		redraw_screen(data);
	}
	return (0);
}

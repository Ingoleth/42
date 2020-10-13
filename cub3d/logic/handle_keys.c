/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:07:13 by user42            #+#    #+#             */
/*   Updated: 2020/10/13 13:24:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int movement_keys(int keycode)
{
    return((keycode == FORWARD || keycode == BACKWARDS || keycode == STRAFE_LEFT
    || keycode == STRAFE_RIGHT));
}

void handle_x_move(s_render_data *render_data)
{
    if (render_data->offset_x > MAX_OFFSET)
    {
        if (render_data->map[render_data->player_y][render_data->player_x + 1] == '1')
            render_data->offset_x = MAX_OFFSET;
        else
        {
            render_data->player_x += 1;
            render_data->offset_x -= MAX_OFFSET;
        } 
    }
    else if (render_data->offset_x < 0)
    {
        if (render_data->map[render_data->player_y][render_data->player_x - 1] == '1')
            render_data->offset_x = 0;
        else
        {
            render_data->player_x -= 1;
            render_data->offset_x += MAX_OFFSET;
        } 
    }
}


void handle_y_move(s_render_data *render_data)
{
    printf("Hello there! (general greivous)\n");
    if (render_data->offset_y > MAX_OFFSET)
    {
        if (render_data->map[render_data->player_y + 1][render_data->player_x] == '1')
            render_data->offset_y = MAX_OFFSET;
        else
        {
            render_data->player_y += 1;
            render_data->offset_y -= MAX_OFFSET;
        } 
    }
    else if (render_data->offset_y < 0)
    {
        if (render_data->map[render_data->player_y - 1][render_data->player_x] == '1')
            render_data->offset_y = 0;
        else
        {
            render_data->player_y -= 1;
            render_data->offset_y += MAX_OFFSET;
        } 
    }
}

void handle_movement(int keycode, cub3d *data)
{
    if (keycode == FORWARD)
        data->render_data->offset_y -= PLAYER_SPEED; //TRANSFORM TO take INTO ACCOUNT THE DIRECTION OF the look vector
    if (keycode == BACKWARDS)
        data->render_data->offset_y += PLAYER_SPEED;
    if (keycode == STRAFE_LEFT)
        data->render_data->offset_x -= PLAYER_SPEED;
    if (keycode == STRAFE_RIGHT)
        data->render_data->offset_x += PLAYER_SPEED;
    handle_x_move(data->render_data);
    handle_y_move(data->render_data);
    calculate_step(&data->ray_trc);
}

int handle_keys (int keycode, cub3d *data)
{
	s_mlx *mlx_data;

	mlx_data = &data->mlx_data;
    
    if (movement_keys(keycode))
        handle_movement(keycode, data->render_data);
    if (keycode == LOOK_LEFT || keycode == LOOK_RIGHT)
        update_angle_info();
    if (data->render_data->view_angle > PI2 || data->render_data->view_angle < 0)
        data->render_data->view_angle = 0;
	if (keycode == ESC)
        close_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	redraw_screen(data);
	return(0);
}
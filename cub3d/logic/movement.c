/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:19:11 by user42            #+#    #+#             */
/*   Updated: 2020/11/04 16:24:06 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void handle_movement(int keycode, cub3d *data)
{
    if (keycode == FORWARD)
        data->render_data->player_y -= PLAYER_SPEED; //TODO TRANSFORM TO take INTO ACCOUNT THE DIRECTION OF the look vector
    if (keycode == BACKWARDS)
        data->render_data->player_y += PLAYER_SPEED;
    if (keycode == STRAFE_LEFT)
        data->render_data->player_x -= PLAYER_SPEED;
    if (keycode == STRAFE_RIGHT)
        data->render_data->player_x += PLAYER_SPEED;
}

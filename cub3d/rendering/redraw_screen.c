/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:55:47 by user42            #+#    #+#             */
/*   Updated: 2020/10/17 11:17:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void print_debug_info(s_mlx *mlx_data, s_render_data *render_data)
{
    char *s1;
    char *s2;
    char *s3;

    s1 = ft_itoa((int)rad_to_degrees(render_data->view_angle));
    s2 = ft_strjoin("Angle: ", s1);
    mlx_string_put(mlx_data->mlx_ptr, mlx_data->win_ptr, render_data->res_x
    - 200, 10, WHITE, s2);
    free(s1);
    free(s2);
    s1 = ft_itoa(render_data->player_x);
    s2 = ft_itoa(render_data->player_y);
    s3 = ft_strjoin("Player x: ", s1);
    free(s1);
    s1 = ft_strjoin("Player y: ", s2);
    free(s2);
    s2 = ft_strjoin(s3, " ");
    free(s3);
    s3 = ft_strjoin(s2, s1);
    free(s2);
    free(s1);
    mlx_string_put(mlx_data->mlx_ptr, mlx_data->win_ptr, render_data->res_x
    - 200, 20, WHITE, s3);
    free(s3);
}

int redraw_screen(cub3d *data)
{
    s_mlx *mlx_data;

    mlx_data = &data->mlx_data;
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->background->img, 0, 0);
    //render_walls();
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->map->img, 0, 0);
    render_cursor(mlx_data, data->render_data);
    print_debug_info(mlx_data, data->render_data);
    return(0);
}
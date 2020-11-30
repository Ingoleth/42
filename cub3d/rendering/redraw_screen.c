/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:55:47 by user42            #+#    #+#             */
/*   Updated: 2020/11/30 18:14:09 by aiglesia         ###   ########.fr       */
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

void render_health_bar(s_mlx *mlx_data, float health_ratio, int pixel_size)
{
    int start_pos_x;
    int start_pos_y;
    int end_pos_x;
    int end_pos_y;

    start_pos_x = HB_START_x * pixel_size;
    start_pos_y = HB_START_Y * pixel_size;
    end_pos_x = start_pos_x + HB_LENGHT_X * mlx_data->health_bar.pixel_size * health_ratio;
    end_pos_y = start_pos_y + HB_LENGHT_Y * mlx_data->health_bar.pixel_size;
    draw_pixel_area(mlx_data->health_bar.image, set_draw_coords(start_pos_x, start_pos_y, end_pos_x, end_pos_y), red_1);
    draw_pixel_area(mlx_data->health_bar.image, set_draw_coords(start_pos_x, start_pos_y, end_pos_x, start_pos_y + pixel_size), red_2);
    draw_pixel_area(mlx_data->health_bar.image, set_draw_coords(start_pos_x, end_pos_y - pixel_size, end_pos_x, end_pos_y), red_2);
    draw_pixel_area(mlx_data->health_bar.image, set_draw_coords(end_pos_x - pixel_size, start_pos_y + pixel_size, end_pos_x, end_pos_y - pixel_size), red_2);
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->health_bar.image->img, mlx_data->map->width + 2 * pixel_size, 0);
}

int redraw_screen(cub3d *data)
{
    s_mlx *mlx_data;

    mlx_data = &data->mlx_data;
    ray_trace(data);
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->background->img, 0, 0);
    if (data->mlx_data.keys_pressed.enter)
    {
        mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->map->img, 0, 0);
        render_cursor(mlx_data, &data->render_data);
        print_debug_info(mlx_data, &data->render_data);
        render_health_bar(mlx_data, 1, mlx_data->health_bar.pixel_size);
    }
    return(0);
}
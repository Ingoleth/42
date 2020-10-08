/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:33:22 by user42            #+#    #+#             */
/*   Updated: 2020/10/08 12:16:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int initialize_render_data(s_mlx *mlx_data, s_render_data *render_data)
{
    if (!(render_data = read_file("/home/user42/Documents/42/cub3d/map")) ||
	check_render_data(render_data, mlx_data->mlx_ptr))
		return ((int)free_render_data(render_data));
    mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, render_data->res_x, render_data->res_y, "Cub3d");
	render_floor_ceiling(render_data, mlx_data);
	render_map(render_data->map, mlx_data, render_data->res_x, render_data->res_y);
    return(0);
}

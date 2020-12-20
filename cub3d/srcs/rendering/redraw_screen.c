/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:55:47 by user42            #+#    #+#             */
/*   Updated: 2020/12/20 11:51:07 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		redraw_screen(t_cub3d *data)
{
	t_mlx *mlx_data;

	mlx_data = &data->mlx_data;
	ray_trace(data);
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr,
	mlx_data->background->img, 0, 0);
	return (0);
}

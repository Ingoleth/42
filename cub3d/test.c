/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:16:58 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/04 20:59:22 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int main (void)
{
	t_data image;
	void *mlx_ptr;

	mlx_ptr = mlx_init();
	ft_memset(&image, 0, sizeof(image));
	add_texture(&image, mlx_ptr, "/home/user42/Documents/42/cub3d/textures/barrel.XPM", 0);
	mlx_destroy_image(mlx_ptr, image.img);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:16:58 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/09 19:13:45 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (void)
{
	t_data image;
	void * mlx_ptr = mlx_init();
	image.img = mlx_xpm_file_to_image(mlx_ptr, "/home/user42/Documents/42_2/cub3d/textures/sand.XPM", &image.width, &image.height);
	if (!image.img)
	{
		printf("Hello there!\n");
		return (0);
	}
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	void *win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "text");
	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 0, 0);
	printf("%i, %i, %i %p\n", image.bits_per_pixel, image.endian, image.line_length, image.addr);
	draw_pixel_area(&image, set_draw_coords(0,0,375,348), get_pixel(&image, 0, 0));
	mlx_loop(mlx_ptr);
}
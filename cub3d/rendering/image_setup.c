/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:28:46 by user42            #+#    #+#             */
/*   Updated: 2020/12/10 13:19:55 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data		*initialize_image(void *mlx_ptr, int size_x, int size_y)
{
	t_data *image;

	if (!(image = ft_calloc(1, sizeof(t_data))))
		return (0);
	image->img = mlx_new_image(mlx_ptr, size_x, size_y);
	image->width = size_x;
	image->height = size_y;
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
	&image->line_length, &image->endian);
	return (image);
}

t_data		*load_xpm_image(void *mlx_ptr, char *path)
{
	t_data *image;

	if (!(image = ft_calloc(1, sizeof(t_data))))
		return (0);
	if (!(image->img = mlx_xpm_file_to_image(mlx_ptr, path, &image->width,
	&image->height)))
		return (0);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
	&image->line_length, &image->endian);
	return (image);
}

void		free_image(void *mlx_ptr, t_data *image)
{
	mlx_destroy_image(mlx_ptr, image->img);
	free(image);
}

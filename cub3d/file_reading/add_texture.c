/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 12:15:44 by user42            #+#    #+#             */
/*   Updated: 2020/11/09 19:14:47 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_texture(t_data *image, void *mlx_ptr, char *line, s_error *error)
{
	image->img = mlx_xpm_file_to_image(mlx_ptr, line, &image->width, &image->height);
	if (!image->img)
	{
		printf("%s\n", line);
		error->error_id = 10;
		return ;
	}
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
}

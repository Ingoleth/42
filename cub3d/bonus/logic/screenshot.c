/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 11:05:51 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/17 00:02:52 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_image(t_data *render, int fd)
{
	int			i;
	int			j;
	unsigned	aux;

	i = 1;
	j = render->height - 1;
	while (j >= 0)
	{
		while (i < render->width)
		{
			aux = get_pixel(render, i, j);
			write(fd, &aux, 4);
			i++;
		}
		i = 0;
		j--;
	}
	return ;
}

void	copy_header(t_data *render, int fd)
{
	int header_info_size;
	int plane_nbr;
	int o_count;

	header_info_size = 40;
	plane_nbr = 1;
	write(fd, &header_info_size, 4);
	write(fd, &render->width, 4);
	write(fd, &render->height, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &render->bits_per_pixel, 2);
	o_count = 0;
	while (o_count < 28)
	{
		write(fd, "\0", 1);
		o_count++;
	}
	return ;
}

/*
**	Prints in order:
**	-Magic byte BM											(2 pixels).
**	-Size of the file										(4 pixels).
**	-Reservado												(4 pixels).
**	-Desajuste de la imagen -donde empiezan los píxeles-	(4 bytes).
**
**	--HEADER--
**	-Tamaño del header										(4 bytes).
**	-Ancho de la imagen										(2 bytes).
**	-Número de planos -Siempre es igual a uno-				(2 bytes).
**  -tamaño del pixel en bytes								(4 bytes).
**	-Reservado												(28 bytes).
**
**	--IMAGEN--
**	Pixels de la imagen (invertidos).
*/

void	take_screenshot(t_data *render)
{
	int fd;
	int file_size;
	int image_start;

	fd = open("cub3d.bmp", O_CREAT | O_RDWR);
	file_size = 14 + 40 + (render->width * render->height) * 4;
	image_start = 14 + 40;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &image_start, 4);
	copy_header(render, fd);
	copy_image(render, fd);
	close(fd);
	return ;
}

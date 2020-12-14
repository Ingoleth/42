/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 11:05:51 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/14 13:23:13 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_image(t_data *render, int fd)
{
	int			i;
	int			j;
	unsigned	aux;

	i = 0;
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

void	take_screenshot(t_data *render)
{
	int fd;
	int file_size;
	int first_pix;

	fd = open("cub3d.bmp", O_CREAT | O_RDWR);
	file_size = 14 + 40 + 4 + (render->width * render->height) * 4;
	first_pix = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	copy_header(render, fd);
	copy_image(render, fd);
	close(fd);
	return ;
}

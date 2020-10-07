/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 12:15:44 by user42            #+#    #+#             */
/*   Updated: 2020/09/25 14:21:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_if_image(char *str)
{
	if (!ft_strncmp(str, "\x89PNG\r\n\x1a\n", 8) ||
			!ft_strncmp(str, "\xff\xd8\xff", 3))
		return (1);
	return (0);
}

int		get_texture_size(int fd, char *path)
{
	int		size;
	int		bytes_read;
	char	str[9];

	size = 0;
	str[8] = 0;
	if ((open(path, O_RDONLY) == -1))
		return (-1);
	while ((bytes_read = read(fd, str, 8)))
	{
		size += bytes_read;
		if (size == 8 && !check_if_image(str))
			return (-1);
	}
	return (size ? size : -1);
}

void	add_texture(char **texture, char *line, s_error *error)
{
	int fd;
	int size;

	if (*texture)
	{
		error->error_id = 3;
		return ;
	}
	while (ft_isspace(*line))
		line++;
	fd = open(line, O_RDONLY);
	if ((size = get_texture_size(fd, line)) == -1)
	{
		error->error_id = 10;
		return ;
	}
	close(fd);
	fd = open(line, O_RDONLY);
	if (!(*texture = ft_calloc(1, size + 1)))
		error->error_id = 1;
	read(fd, *texture, size);
	return ;
}

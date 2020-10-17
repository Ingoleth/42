/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:23:24 by user42            #+#    #+#             */
/*   Updated: 2020/10/17 11:44:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			free_textures(s_render_data *render_data)
{
	if (render_data->east_texture)
		free(render_data->east_texture);
	if (render_data->north_texture)
		free(render_data->north_texture);
	if (render_data->west_texture)
		free(render_data->west_texture);
	if (render_data->south_texture)
		free(render_data->south_texture);
	if (render_data->sprite)
		free(render_data->sprite);
}

s_render_data	*free_render_data(s_render_data *render_data)
{
	int i;

	i = 0;
	if (render_data)
	{
		if (render_data->map)
		{
			while (render_data->map[i])
			{
				free(render_data->map[i]);
				i++;
			}
			free(render_data->map);
		}
		free_textures(render_data);
		free(render_data);
	}
	
	return (0);
}

int				read_actual_file(s_render_data *render_data,
s_error *error, char **line, char *data_file)
{
	s_file_descriptor	file;
	int					i;

	file.path = data_file;
	if ((file.fd = open(data_file, O_RDONLY)) && file.fd == -1)
		error->error_id = 2;
	while (!(error->error_id && print_error(error)))
	{
		i = get_next_line(file.fd, line);
		fill_render_struct(render_data, *line, error, &file);
		if (!error->error_id)
		{
			error->line++;
			error->row = 0;
		}
		if (!i)
			break ;
	}
	return (file.fd);
}

void			end_get_next_line(char *line, int fd)
{
	while (get_next_line(fd, &line))
	{
		free(line);
	}
	if (line)
		free(line);
}

s_render_data	*read_file(char *data_file)
{
	s_render_data	*render_data;
	s_error			*error;
	char			*line;
	int				fd;

	if (!(render_data = ft_calloc(1, sizeof(s_render_data))))
		return (0);
	if (!(error = ft_calloc(1, sizeof(s_error))))
		return (free_render_data(render_data));
	fd = read_actual_file(render_data, error, &line, data_file);
	if (error->error_id)
	{
		if (fd != -1)
			end_get_next_line(line, fd);
		free(error);
		free_render_data(render_data);
		return (0);
	}
	free(error);
	return (render_data);
}

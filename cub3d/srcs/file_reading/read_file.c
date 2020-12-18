/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:23:24 by user42            #+#    #+#             */
/*   Updated: 2020/12/17 00:02:52 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			free_textures(s_render_data *render_data, void *mlx_ptr)
{
	if (render_data->east_texture.img)
		mlx_destroy_image(mlx_ptr, render_data->east_texture.img);
	if (render_data->north_texture.img)
		mlx_destroy_image(mlx_ptr, render_data->north_texture.img);
	if (render_data->west_texture.img)
		mlx_destroy_image(mlx_ptr, render_data->west_texture.img);
	if (render_data->south_texture.img)
		mlx_destroy_image(mlx_ptr, render_data->south_texture.img);
	if (render_data->sprite1.img)
		mlx_destroy_image(mlx_ptr, render_data->sprite1.img);
}

int				free_render_data(s_render_data *render_data, void *mlx_ptr)
{
	int i;

	i = 0;
	if (render_data->map)
	{
		while (render_data->map[i])
		{
			free(render_data->map[i]);
			i++;
		}
		free(render_data->map);
	}
	if (render_data->extra_level)
		free(render_data->extra_level);
	free_textures(render_data, mlx_ptr);
	return (0);
}

int				read_actual_file(s_render_data *render_data,
s_error *error, char **line, char *data_file)
{
	s_file_descriptor	file;
	int					i;

	file.path = data_file;
	if (ft_strncmp(data_file + ft_strlen(data_file) - 4, ".cub", 4))
		error->error_id = file_not_cub;
	else if ((file.fd = open(data_file, O_RDONLY)) && file.fd == -1)
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

s_render_data	*read_file(char *data_file, s_render_data *render_data,
void *mlx_ptr)
{
	s_error			error;
	char			*line;
	int				fd;
	char			aux[2];

	ft_memset(render_data, 0, sizeof(s_render_data));
	ft_memset(&error, 0, sizeof(error));
	render_data->mlx_ptr = mlx_ptr;
	fd = read_actual_file(render_data, &error, &line, data_file);
	if (error.error_id)
	{
		if (fd != -1 && read(fd, aux, 1))
			end_get_next_line(fd);
		return (0);
	}
	return (render_data);
}

char			*skip_spaces(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

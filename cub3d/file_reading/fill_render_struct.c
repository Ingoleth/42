/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_render_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:34:39 by user42            #+#    #+#             */
/*   Updated: 2020/11/28 11:04:47 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		advance_numbers(char **line, s_error *error, int i)
{
	while (ft_isspace(**line) || (i == 1 && **line == ',' && i++))
		advance_file_line(line, error);
	while (**line)
	{
		if (ft_isdigit(**line))
			advance_file_line(line, error);
		else if (ft_isspace(**line) || (i > 0 && **line == ','))
		{
			if (**line == ',')
				*line = *line + 1;
			break ;
		}
		else
			return (1);
	}
	return (0);
}

int		fill_resolution(char *line, s_render_data *render_data, s_error *error)
{
	if (!(render_data->res_x = ft_atoi(line)))
		return (4);
	if (advance_numbers(&line, error, 0))
		return (error->error_id = 4);
	if (!(render_data->res_y = ft_atoi(line)))
		return (error->error_id = 4);
	while (*line)
	{
		if (ft_isspace(*line) || ft_isdigit(*line))
			advance_file_line(&line, error);
		else
			return (error->error_id = 4);
	}
	return (0);
}

int		fill_colour(unsigned int *colour, char *line, s_error *error)
{
	int r;
	int g;
	int b;

	r = ft_atoi(line);
	if (r > 255 || advance_numbers(&line, error, 1))
		return (error->error_id = 11);
	g = ft_atoi(line);
	if (g > 255 || advance_numbers(&line, error, 1))
		return (error->error_id = 11);
	b = ft_atoi(line);
	if (b > 255)
		return (error->error_id = 11);
	while (*line)
	{
		if (ft_isspace(*line) || ft_isdigit(*line))
			advance_file_line(&line, error);
		else
			return (error->error_id = 11);
	}
	*colour = get_trgb(1, r, g, b);
	return (0);
}

int		handle_textures(char *line, s_render_data *render_data, s_error *error)
{
	if (!(ft_strncmp(line, "NO", 2)))
		add_texture(&render_data->north_texture, render_data->mlx_ptr, line + 2, error);
	else if (!(ft_strncmp(line, "SO", 2)))
		add_texture(&render_data->south_texture, render_data->mlx_ptr, line + 2, error);
	else if (!(ft_strncmp(line, "WE", 2)))
		add_texture(&render_data->west_texture, render_data->mlx_ptr, line + 2, error);
	else if (!(ft_strncmp(line, "EA", 2)))
		add_texture(&render_data->east_texture, render_data->mlx_ptr, line + 2, error);
	else if (!(ft_strncmp(line, "S2", 2)))
		add_texture(&render_data->sprite1, render_data->mlx_ptr, line + 2, error);
	else if (!(ft_strncmp(line, "S3", 2)))
		add_texture(&render_data->sprite2, render_data->mlx_ptr, line + 2, error);
	else if (!(ft_strncmp(line, "S4", 2)))
		add_texture(&render_data->sprite3, render_data->mlx_ptr, line + 2, error);
	else if (line[0] == 'C')
		fill_colour(&render_data->c_rgb, line + 1, error);
	else if (line[0] == 'F')
		fill_colour(&render_data->f_rgb, line + 1, error);
	else
		return (0);
	return (1);
}

void	fill_render_struct(s_render_data *render_data, char *line,
s_error *error, s_file_descriptor *file)
{
	if (!line || *line == 0)
		error->error_id = 0;
	else if (*line == 'R')
		fill_resolution(line + 1, render_data, error);
	else if (handle_textures(line, render_data, error))
		error->error_id = error->error_id;
	else if (*line == '1' || *line == ' ')
	{
		handle_map(render_data, error, line, file);
		return ;
	}
	else
	{
		free(line);
		error->error_id = 5;
		return ;
	}
	free(line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_render_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:34:39 by user42            #+#    #+#             */
/*   Updated: 2020/12/20 11:35:32 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		advance_numbers(char **line, t_error *error, int i)
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

int		fill_resolution(char *line, t_render_data *render_data, t_error *error)
{
	if (!(render_data->res_x = ft_atoi(line)))
		return (4);
	if (advance_numbers(&line, error, 0))
		return (error->error_id = wrong_resolution);
	if (!(render_data->res_y = ft_atoi(line)))
		return (error->error_id = wrong_resolution);
	while (ft_isspace(*line))
		advance_file_line(&line, error);
	while (*line)
	{
		if (ft_isdigit(*line))
			advance_file_line(&line, error);
		else
			return (error->error_id = wrong_resolution);
	}
	return (0);
}

int		fill_colour(unsigned int *colour, char *line, t_error *error)
{
	int r;
	int g;
	int b;

	if (*colour)
		return (error->error_id = repeated_colour);
	r = ft_atoi(line);
	if (r > 255 || !ft_isdigit(*line) || advance_numbers(&line, error, 1))
		return (error->error_id = wrong_colour);
	g = ft_atoi(line);
	if (g > 255 || !ft_isdigit(*line) || advance_numbers(&line, error, 1))
		return (error->error_id = wrong_colour);
	b = ft_atoi(line);
	if (b > 255 || !ft_isdigit(*line))
		return (error->error_id = wrong_colour);
	while (ft_isspace(*line))
		advance_file_line(&line, error);
	check_remainding_colour(line, error);
	*colour = get_trgb(1, r, g, b);
	return (0);
}

int		handle_textures(char *line, t_render_data *render_data, t_error *error)
{
	if (!(ft_strncmp(line, "NO ", 3)))
		add_texture(&render_data->north_texture, render_data->mlx_ptr,
		skip_spaces(line + 3), error);
	else if (!(ft_strncmp(line, "SO ", 3)))
		add_texture(&render_data->south_texture, render_data->mlx_ptr,
		skip_spaces(line + 3), error);
	else if (!(ft_strncmp(line, "WE ", 3)))
		add_texture(&render_data->west_texture, render_data->mlx_ptr,
		skip_spaces(line + 3), error);
	else if (!(ft_strncmp(line, "EA ", 3)))
		add_texture(&render_data->east_texture, render_data->mlx_ptr,
		skip_spaces(line + 3), error);
	else if (!(ft_strncmp(line, "S ", 2)))
		add_texture(&render_data->sprite1, render_data->mlx_ptr,
		skip_spaces(line + 2), error);
	else
		return (0);
	return (1);
}

void	fill_render_struct(t_render_data *render_data, char *line,
t_error *error, t_file_descriptor *file)
{
	char *aux;

	if (*line == 'R')
		fill_resolution(line + 1, render_data, error);
	else if (handle_textures(line, render_data, error))
		error->error_id = error->error_id;
	else if (line[0] == 'C')
		fill_colour(&render_data->c_rgb, skip_spaces(line + 1), error);
	else if (line[0] == 'F')
		fill_colour(&render_data->f_rgb, skip_spaces(line + 1), error);
	else if ((ft_isdigit(*line) || *line == ' ') && (aux = line)
	&& !advance_numbers(&aux, error, false))
	{
		handle_map(render_data, error, line, file);
		return ;
	}
	else if (*line)
	{
		free(line);
		error->error_id = wrong_input;
		return ;
	}
	free(line);
}

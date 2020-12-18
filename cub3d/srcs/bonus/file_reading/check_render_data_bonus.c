/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_render_data_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:26:29 by user42            #+#    #+#             */
/*   Updated: 2020/12/18 17:01:51 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	check_textures(s_render_data *render_data)
{
	char *aux;

	aux = 0;
	if (!render_data->north_texture.img)
		aux = "north";
	if (!render_data->east_texture.img)
		aux = "east";
	if (!render_data->south_texture.img)
		aux = "south";
	if (!render_data->west_texture.img)
		aux = "west";
	if (render_data->is_sp1 && !render_data->sprite1.img)
		aux = "sprite (1)";
	if (render_data->is_sp2 && !render_data->sprite2.img)
		aux = "sprite (2)";
	if (render_data->is_sp3 && !render_data->sprite3.img)
		aux = "sprite (3)";
	if (aux)
	{
		ft_putstr_fd("Error\nMissing ", 1);
		ft_putstr_fd(aux, 1);
		ft_putstr_fd(" texture!\n", 1);
	}
	return (aux ? true : false);
}

int		check_colour(s_render_data *render_data)
{
	char *aux;

	aux = 0;
	if (!get_t(render_data->c_rgb))
		aux = "ceiling ";
	else if (!get_t(render_data->c_rgb))
		aux = "floor";
	if (aux)
	{
		ft_putstr_fd("Error\nMissing ", 1);
		ft_putstr_fd(aux, 1);
		ft_putstr_fd("colour!\n", 1);
	}
	return (aux ? true : false);
}

int	check_resolution(void *mlx_ptr, s_render_data *render_data)
{
	int x;
	int y;

	mlx_get_screen_size(mlx_ptr, &x, &y);
	if (render_data->res_x > x)
	{
		ft_putstr_fd("Warning:\nX resolution is bigger than screen size!\n", 1);
		ft_putstr_fd("Setting to screen size...\n", 1);
		render_data->res_x = x;
	}
	if (render_data->res_y > y)
	{
		ft_putstr_fd("Warning:\nY resolution is bigger than screen size!\n", 1);
		ft_putstr_fd("Setting to screen size...\n", 1);
		render_data->res_y = y;
	}
	if (!render_data->res_x || !render_data->res_y)
		return (1);
	return (0);
}

int		check_render_data(s_render_data *render_data, void *mlx_ptr)
{
	if (!render_data)
		return (0);
	if (check_textures(render_data))
		return (1);
	else if (check_colour(render_data))
		return (1);
	if (!render_data->map)
	{
		ft_putstr_fd("Error\nMissing map;\n", 1);
		return (1);
	}
	if(check_resolution(mlx_ptr, render_data))
	{
		ft_putstr_fd("Error\nNo resolution input!\n", 1);
		return(1);
	}
	return (0);
}

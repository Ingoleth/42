/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_render_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:33:22 by user42            #+#    #+#             */
/*   Updated: 2020/12/20 13:07:01 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_face_data(t_data **face_temp, float *width, void *mlx_ptr,
float ratio)
{
	*face_temp = load_xpm_image(mlx_ptr,
	"/home/user42/Documents/42/cub3d/textures/face.xpm");
	(*face_temp)->addr = mlx_get_data_addr((*face_temp)->img,
	&(*face_temp)->bits_per_pixel, &(*face_temp)->line_length,
	&(*face_temp)->endian);
	*width = 12 * ratio;
	*width = (int)*width > 0 ? *width : 1;
}

void	load_face(t_health_bar *health_bar, void *mlx_ptr, float ratio,
t_data *health_bar_temp)
{
	t_data	*face_temp;
	int		i;
	int		j;
	float	width;

	load_face_data(&face_temp, &width, mlx_ptr, ratio);
	health_bar->face_pos = 2 * ratio;
	health_bar->face = initialize_image(mlx_ptr, 2 * width, width);
	i = 0;
	j = 0;
	ratio = face_temp->height / width;
	while (i < 2 * width)
	{
		while (j < width)
		{
			draw_pixel(health_bar->face, i, j,
			get_pixel(face_temp, i / (width * 2) *
			face_temp->width, j / width * face_temp->height));
			j++;
		}
		i++;
		j = 0;
	}
	free_image(mlx_ptr, face_temp);
	free_image(mlx_ptr, health_bar_temp);
}

t_data	*load_health_bar_info(t_mlx *mlx_data, float bar_width,
float bar_height)
{
	t_data *health_bar_temp;

	health_bar_temp = load_xpm_image(mlx_data->mlx_ptr, HEALTH_BAR_PATH);
	mlx_data->health_bar.image = initialize_image(mlx_data->mlx_ptr,
	bar_width, bar_height);
	mlx_data->health_bar.pixel_size = (int)bar_width /
	(float)health_bar_temp->width;
	mlx_data->health_bar.bar_start_x = HB_START_X *
	(mlx_data->health_bar.image->width / (float)health_bar_temp->width);
	mlx_data->health_bar.bar_start_y = HB_START_Y *
	(mlx_data->health_bar.image->height / (float)health_bar_temp->height);
	mlx_data->health_bar.bar_lenght_x = (HB_LENGHT_X) *
	(mlx_data->health_bar.image->width / (float)health_bar_temp->width);
	mlx_data->health_bar.bar_lenght_y = (HB_LENGHT_Y) *
	(mlx_data->health_bar.image->height / (float)health_bar_temp->height);
	return (health_bar_temp);
}

void	load_health_bar(t_mlx *mlx_data, int res)
{
	t_data	*hb_t;
	float	bar_width;
	float	bar_height;
	int		j;

	bar_width = res / MAP_RATIO > 0 ? res / MAP_RATIO : 1;
	bar_height = (int)(bar_width / 4) > 0 ? bar_width / 4 : 1;
	hb_t = load_health_bar_info(mlx_data, bar_width, bar_height);
	res = 0;
	j = 0;
	while (res < bar_width)
	{
		while (j < bar_height)
		{
			draw_pixel(mlx_data->health_bar.image, res, j,
			get_pixel(hb_t, (int)(res / bar_width *
			hb_t->width), (int)(j /
			bar_height * hb_t->height)));
			j++;
		}
		res++;
		j = 0;
	}
	load_face(&mlx_data->health_bar, mlx_data->mlx_ptr,
	(mlx_data->health_bar.image->width / (float)hb_t->width), hb_t);
}

int		initialize_render_data(t_mlx *mlx_data, t_cub3d *data, char *file_path)
{
	if (!read_file(file_path, &data->render_data, mlx_data->mlx_ptr) ||
	check_render_data(&data->render_data, mlx_data->mlx_ptr))
		return (0);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr,
	data->render_data.res_x, data->render_data.res_y, "Cub3d");
	mlx_data->background = initialize_image(mlx_data->mlx_ptr,
	data->render_data.res_x, data->render_data.res_y);
	load_map(data->render_data.map, mlx_data, data->render_data.res_x,
	data->render_data.res_y);
	load_health_bar(mlx_data, data->render_data.res_x >
	data->render_data.res_y ? data->render_data.res_y :
	data->render_data.res_x);
	load_cursor(mlx_data, data->render_data.view_angle);
	data->render_data.column_height = data->render_data.res_x /
	(tan(FOV / 2 ) * 2);
	data->render_data.current_health = MAX_HEALTH;
	data->mlx_data.keys_pressed.enter = true;
	data->render_data.shade_distance = SHADE_DISTANCE;
	redraw_screen(data);
	return (1);
}

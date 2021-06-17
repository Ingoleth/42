#include "FdF.h"

t_data		*initialize_image(void *mlx_ptr, int size_x, int size_y) //NOTE change FT_CALLOC
{
	t_data *image;

	if (!(image = calloc(1, sizeof(t_data))))
		return (0);
	image->img = mlx_new_image(mlx_ptr, size_x, size_y);
	image->width = size_x;
	image->height = size_y;
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
	&image->line_length, &image->endian);
	return (image);
}

void	render_image(t_data *canvas, t_data *image, int x, int y, float size)
{
	int i;
	int j;
	int pixel;

	i = 0;
	j = 0;

	while (i < size)
	{
		while (j < size)
		{
			if ((x + j >= 0 && x + j < 1920) && (y + i >= 0 && y + i < 1080))
			{
				pixel = get_pixel(image, image->width * (j / size), image->height * (i / size));
				if (pixel != -16777216)
					draw_pixel(canvas, x + j, y + i, pixel);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

t_data		*load_xpm_image(void *mlx_ptr, char *path)
{
	t_data *image;

	if (!(image = calloc(1, sizeof(t_data))))
		return (0);
	if (!(image->img = mlx_xpm_file_to_image(mlx_ptr, path, &image->width,
	&image->height)))
		return (0);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
	&image->line_length, &image->endian);
	return (image);
}

void		free_image(void *mlx_ptr, t_data *image)
{
	mlx_destroy_image(mlx_ptr, image->img);
	free(image);
}
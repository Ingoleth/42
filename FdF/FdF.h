#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				height;
	int				width;
}					t_data;


typedef struct		s_write_coords
{
	int				x;
	int				y;
	int				end_x;
	int				end_y;
}					t_coords;

t_data		*initialize_image(void *mlx_ptr, int size_x, int size_y);
t_data		*load_xpm_image(void *mlx_ptr, char *path);
t_coords	set_draw_coords(int x, int y, int end_x, int end_y);
unsigned	get_pixel(t_data *image, int x, int y);
void		draw_pixel(t_data *image, int x, int y, int color);
void		draw_pixel_area(t_data *image, t_coords coords, int color);
void	    render_image(t_data *canvas, t_data *image, int x, int y, float size);
int			**get_map();

#endif

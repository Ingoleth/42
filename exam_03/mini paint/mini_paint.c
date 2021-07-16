#include "mini_paint.h"

void print(t_render *render_data)
{
	int max_size;
	int i;
	int j;

	i = 0;
	j = 0;
	max_size = render_data->width * render_data->height;
	while (i < max_size)
	{
		while (j < render_data->width)
		{
			write(STDOUT_FILENO, &render_data->screen[i + j], 1);
			j++;
		}
		write(STDOUT_FILENO, "\n", 1);
		j = 0;
		i += render_data->width;
	}
}

void	draw(int i, int j, char c, t_render *render_data)
{
	render_data->screen[i * render_data->width + j] = c;	
}

int	get_zone(t_render *render_data, FILE *file)
{
	if (fscanf(file, "%d %d %c\n", &render_data->width, &render_data->height, &render_data->background) != 3)
		return (1);
	if (render_data->height < 1 || render_data->height > 300 || render_data->width < 1 || render_data->width > 300)
		return (1);
	if (!(render_data->screen = malloc((render_data->height * render_data->width + 1) * sizeof(char))))
		return (1);
	render_data->screen[render_data->height * render_data->width] = 0;
	memset(render_data->screen, render_data->background, render_data->height * render_data->width);
	return (0);
}

void draw_circle(t_render *render_data, t_circle circle)
{
	float distance;
	float i;
	float j;
	int characters_checked;
	int max_size;

	max_size = render_data->width * render_data->height;
	characters_checked = 0;
	i = 0;
	j = 0;
	while (characters_checked < max_size)
	{
		while (j < render_data->width)
		{
			distance = sqrt((circle.x - j) * (circle.x - j) + (circle.y - i) * (circle.y - i));
			if (circle.type == 'c' && circle.radius - distance < 1.0 && circle.radius - distance >= 0)
				draw(i, j, circle.drawing_char, render_data);
			if (circle.type == 'C' && distance <= circle.radius)
				draw(i, j, circle.drawing_char, render_data);
			j++;
		}
		j = 0;
		i++;
		characters_checked += render_data->width;
	}
}

int	get_circles(t_render *render_data, FILE *file)
{
	int error;
	t_circle circle;

	while ((error = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.drawing_char)) == 5)
	{
		if (circle.radius <= 0.00000000 || (circle.type != 'c' && circle.type != 'C'))
			return (1);
		draw_circle(render_data, circle);
	}
	if (error == -1)
		return (0);
	return (1);
}

int main(int argc, char const *argv[])
{
	int			error;
	FILE		*file;
	t_render	render_data;

	if (argc != 2)
	{
		write(STDOUT_FILENO, "Error: argument\n", 16);
		return (1);
	}
	memset(&render_data, 0, sizeof(render_data));
	error = 0;
	if ((file = fopen(argv[1], "r")) == NULL)
		error = 1;
	else
	{
		error = get_zone(&render_data, file);
		if (!error)
			error = get_circles(&render_data, file);
	}
	if (error)
	{
		if (render_data.screen)
			free(render_data.screen);
		write(STDOUT_FILENO, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	print(&render_data);
	fclose(file);
	return (0);
}

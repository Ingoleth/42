#include "mini_paint.h"

int	get_zone(t_data *data, FILE *file)
{
	if ((fscanf(file, "%d %d %c\n", &data->width, &data->height, &data->background)) == 3)
	{
		if (data->width > 0 && data->height > 0 && data->width < 301 && data->height < 301)
		{
			if ((data->screen = malloc((data->width * data->height + 1) * sizeof(char))))
			{
				data->screen[data->width * data->height] = 0;
				memset(data->screen, data->background, data->width * data->height);
				return (1);
			}
		}
	}
	return (0);
}

void	draw_circle(t_data *data, t_circle circle)
{
	float i;
	float j;
	int max_chars;
	int chars_done;
	float distance;

	max_chars = data->height * data->width;
	i = 0;
	j = 0;
	chars_done = 0;
	while (chars_done < max_chars)
	{
		while (j < data->width)
		{
			distance = sqrt((circle.x - j) * (circle.x - j) + (circle.y - i) * (circle.y - i));
			if (circle.type == 'c')
			{
				if (circle.radius - distance >= 0 && circle.radius - distance < 1)
					data->screen[chars_done + (int)j] = circle.c;
			}
			else
			{
				if (distance <= circle.radius)
					data->screen[(int)i * data->width + (int)j] = circle.c;	
			}
			j++;
		}
		i++;
		j = 0;
		chars_done += data->width;
	}
}

int	perform_operations(t_data *data, FILE *file)
{
	int ret;
	t_circle circle;

	while ((ret = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.c)) == 5)
	{
		if ((circle.type != 'c' && circle.type != 'C') || circle.radius <= 0.0)
			return (0);
		draw_circle(data, circle);
	}
	if (ret == -1)
		return (1);
	return(0);
}

void print_screen(t_data *data)
{
	int i;
	int j;
	int max_chars;

	i = 0;
	j = 0;
	max_chars = data->width * data->height;
	while (i < max_chars)
	{
		while (j < data->width)
		{
			write(STDOUT_FILENO, &data->screen[i + j], 1);
			j++;
		}
		write(STDOUT_FILENO, "\n", 1);
		i += data->width;
		j = 0;
	}
	
}

int main (int argc, char **argv)
{
	FILE *file;
	int print;
	t_data data;

	if (argc != 2)
	{
		write(STDOUT_FILENO, "Error: argument\n", 16);
		return(1);
	}
	if ((file = fopen(argv[1], "r")))
	{
		memset(&data, 0, sizeof(data));
		if (get_zone(&data, file))
		{
			if ((print = perform_operations(&data, file)))
				print_screen(&data);
			fclose(file);
			free(data.screen);
			if (print)
				return (0);
		}
	}
	write(STDOUT_FILENO, "Error: Operation file corrupted\n", 32);
	return (1);
}

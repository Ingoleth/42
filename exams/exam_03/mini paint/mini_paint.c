#include "mini_paint.h"

void print_screen(t_data *data)
{
	for (int i = 0; i < data->heigth; i++)
	{
		write(1, &data->screen[data->width * i], data->width);
		write(1, "\n", 1);
	}
}

int get_screen_data(t_data *data)
{
	if (fscanf(data->file, "%i %i %c\n", &data->width, &data->heigth, &data->background) == 3)
	{
		if (data->heigth <= 0 || data->heigth > 300 || data->width <= 0 || data->width > 300)
			return (0);
		if (!(data->screen = malloc(data->heigth * data->width + 1)))
			return (0);
		memset(data->screen, data->background, data->heigth * data->width);
		data->screen[data->heigth * data->width] = 0;
		return (1);
	}
	return (0);
}

int print_circles(t_data *data)
{
	t_circle circle;
	int ret;
	float distance;

	while ((ret = fscanf(data->file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.to_write)) == 5)
	{
		if (circle.radius <= 0 || (circle.type != 'c' && circle.type != 'C'))
			return (0);
		for(int i = 0; i < data->heigth; i++)
		{
			for(int j = 0; j < data->width; j++)
			{
				distance = sqrtf(powf(circle.x - j, 2) + powf(circle.y - i, 2));
				if (distance <= circle.radius)
				{
					if (circle.type != 'c' || distance > circle.radius - 1)
						data->screen[i * data->width + j] = circle.to_write;
				}
			}	
		}
	}
	if (ret != -1)
		return (0);
	return (1);
	
}

int main (int argc, char **argv)
{
	t_data data;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	memset(&data, 0, sizeof(t_data));
	if ((data.file = fopen(argv[1], "r")))
	{
		if (get_screen_data(&data))
		{
			if (print_circles(&data))
			{
				print_screen(&data);
				free(data.screen);
				return (0);
			}
			free(data.screen);
		}
	}
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);	
}
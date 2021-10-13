#ifndef MINI_PAINT_H
#define MINI_PAINT_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct s_circle
{
	char type;
	float x;
	float y;
	float radius;
	char to_write;
} t_circle;

typedef struct s_data
{
	char *screen;
	int width;
	int heigth;
	char background;
	FILE *file;
}				t_data;

#endif
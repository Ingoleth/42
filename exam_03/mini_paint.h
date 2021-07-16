#ifndef MINI_PAINT_H
#define MINI_PAINT_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct	s_data
{
	int width;
	int height;
	char *screen;
	char background;
}				t_data;

typedef struct	s_circle
{
	char type;
	float x;
	float y;
	float radius;
	char  c;
}				t_circle;

#endif
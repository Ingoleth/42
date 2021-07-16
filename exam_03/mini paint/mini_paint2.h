#ifndef MINIPAINT_H
# define MINIPAINT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct	s_circle
{
	char type;
	float radius;
	float x;
	float y;
	char drawing_char;
}				t_circle;

typedef struct	s_render
{
	int		width;
	int		height;
	char	background;
	char	*screen;
}				t_render;

# endif
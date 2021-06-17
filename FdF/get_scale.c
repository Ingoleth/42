#include "FdF.h"

void get_x_y_axis_length(int **map, int *x, int *y)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        if (map[i][0] > j)
            j = map[i][0];
        i++;
    }
    *x = j;
    *y = i;
}

void get_z_axis_length(int **map, int *z)
{
    int pos;
    int neg;
    int i;
    int j;

    i = 0;

    pos = 0;
    neg = 0;
    while (map[i])
    {
        j = 1;
        while (j <= map[i][0])
        {
            if (map[i][j] > pos)
                pos = map[i][j];
            else if (map[i][j] < neg)
                pos = map[i][j];
            j++;
        }
        i++;
    }
    *z = pos - neg;
}

int get_scale(int **map)
{
    int     x;
    int     y;
    int     z;
    float   scale;

    get_x_y_axis_length(map, &x, &y);
    get_z_axis_length(map, &z);
    scale = 1080 / ((float)(z + (y + x)) * sin(M_PI_4 / 2));
    return (scale);
}
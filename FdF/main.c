#include "FdF.h"

int    cleanup()
{
    exit(0);
}

int on_key_pressed(int key_code)
{
    if (key_code == 65307)
        cleanup();
    return (0);
}

void    draw_tile(int x, int y, int scale, t_data *canvas, t_data *tile)
{
    render_image(canvas, tile, scale * x / 2 -scale * y / 2, scale * x / 4 + scale * y / 4, scale);
}

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_data  *canvas;
    t_data  *tile;
    int     **map;


    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1920, 1280, "FdF");
    tile = load_xpm_image(mlx_ptr, "tile_2.xpm");
    canvas = initialize_image(mlx_ptr, 1920, 1280);
    map = get_map("map");
    tile++;

    int i = 0;
    int j = 1;
    while (map[i])
    {
        while (j <= map[i][0])
        {
            printf("%2i", map[i][j]);
            j++;
        }
        printf("\n");
        j = 1;
        i++;
    }
    
    
    exit(-1);
    mlx_put_image_to_window(mlx_ptr, win_ptr, canvas->img, 0, 0);
    mlx_hook(win_ptr, 2, 1L << 0, on_key_pressed, NULL);
    mlx_hook(win_ptr, 33, 0, cleanup, NULL);
    mlx_loop(mlx_ptr);
}
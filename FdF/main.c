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

void    draw_tile(int x, int y, int scale, t_render_info *render_info)
{
    render_image(render_info->canvas, render_info->tile, 1080 / 8 + 420 + scale * x / 2 -scale * y / 2, 1080 / 8 + scale * x / 4 + scale * y / 4, scale);
}

void    initialize_render_info(t_render_info *render_info)
{
    render_info->mlx_ptr = mlx_init();
    render_info->win_ptr = mlx_new_window(render_info->mlx_ptr, 1920, 1280, "FdF");
    render_info->tile = load_xpm_image(render_info->mlx_ptr, "tile_2.xpm");
    render_info->canvas = initialize_image(render_info->mlx_ptr, 1920, 1280);
    render_info->map = get_map("map");
    render_info->scale = get_scale(render_info->map, &render_info->x, &render_info->y);
}

int main(void)
{
    t_render_info render_info;

    initialize_render_info(&render_info);
    int i = 0;
    int j = 1;
    while (render_info.map[i])
    {
        while (j <= render_info.map[i][0])
        {
            if (render_info.map[i][j])
                draw_tile(j - 1, i, render_info.scale, &render_info);
            j++;
        }
        j = 1;
        i++;
    }
    mlx_put_image_to_window(render_info.mlx_ptr, render_info.win_ptr, render_info.canvas->img, 0, 0);
    mlx_hook(render_info.win_ptr, 2, 1L << 0, on_key_pressed, NULL);
    mlx_hook(render_info.win_ptr, 33, 0, cleanup, NULL);
    mlx_loop(render_info.mlx_ptr);
}
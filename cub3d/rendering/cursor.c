/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 09:35:38 by user42            #+#    #+#             */
/*   Updated: 2020/10/03 10:42:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data  **initialize_cursor(void *mlx_ptr)
{
    t_data **cursor;
    if(!(cursor = ft_calloc(8, sizeof(t_data *))))
        return (0);
    cursor[0] = initialize_xpm_image(mlx_ptr, "./textures/cursor/cursor_north.xpm");
    cursor[1] = initialize_xpm_image(mlx_ptr, "./textures/cursor/cursor_north_east.xpm");
    cursor[2] = initialize_xpm_image(mlx_ptr, "./textures/cursor/cursor_east.xpm");
    cursor[3] = initialize_xpm_image(mlx_ptr, "./textures/cursor/cursor_south_east.xpm");
    cursor[4] = initialize_xpm_image(mlx_ptr, "./textures/cursor/cursor_south.xpm");
    cursor[5] = initialize_xpm_image(mlx_ptr, "./textures/cursor/cursor_south_west.xpm");
    cursor[6] = initialize_xpm_image(mlx_ptr, "./textures/cursor/cursor_west.xpm");
    cursor[7] = initialize_xpm_image(mlx_ptr, "./textures/cursor/cursor_north_west.xpm");
    return(cursor);
}
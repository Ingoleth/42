/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:17:18 by user42            #+#    #+#             */
/*   Updated: 2020/10/10 14:20:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int    close_window(void *mlx_ptr, void *win_ptr)
{
    mlx_destroy_window(mlx_ptr, win_ptr);
    exit(0);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:16:58 by aiglesia          #+#    #+#             */
/*   Updated: 2020/10/30 10:14:29 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (void)
{
	s_render_data *render_data = read_file("/home/user42/Documents/42/cub3d/map");
	free_render_data(render_data);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:16:58 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/08 17:40:55 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (void)
{
	int i;
	i = 0;
	float angle = 0;
	while (i < 360)
	{
		angle += ANGLE_1;
		printf("Sector = %i; Angle = %f, tan = %f\n", get_sector(angle), rad_to_degrees(angle), handle_tan(angle));
		i++;
	}
	
}
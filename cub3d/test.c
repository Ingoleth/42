/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:16:58 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/04 18:32:08 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (void)
{
	float angle;
	int res_x = 50;
	int i = 0;
	float res_x_2 = res_x / 2; 
	float aux;
	while (i < res_x / 2)
	{
		aux = (res_x_2 - (float)i) / res_x_2;
		angle = acos(aux); //*POV/180
		printf("%f; %f, res_x_2 = %f, I = %i\n", rad_to_degrees(angle), aux, res_x_2, i);
		i++;
	}
	//Si la resolución es impar, lanzar angle a 90(*POV/180);
	while (i <= res_x)
	{
		aux = (res_x_2 - (float)i) / res_x_2;
		angle = acos(aux);
		printf("%f; %f, res_x_2 = %f, I = %i\n", rad_to_degrees(angle), aux, res_x_2, i);
		i++;
	}
}
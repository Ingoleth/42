/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:16:58 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/01 13:34:50 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (void)
{
	t_collision *str;
	t_collision *aux;
	str = 0;
	add_collision_tile(&str, 2, 1);
	add_collision_tile(&str, 1, 2);
	add_collision_tile(&str, 3, 1);
	add_collision_tile(&str, 1, 3);
	add_collision_tile(&str, 4, 1);
	add_collision_tile(&str, 1, 4);
	aux = str;
	while (aux)
	{
		printf("x = %i; y = %i; Dirty: %i\n", aux->x, aux->y, aux->not_dirty);
		aux = aux->next;
	}
	printf("---\n");
	clean_dirty_collision_tiles(&str);
	aux = str;
	while (aux)
	{
		printf("x = %i; y = %i; Dirty: %i\n", aux->x, aux->y, aux->not_dirty);
		aux = aux->next;
	}
	printf("---\n");
	str->not_dirty = 1;
	str->next->next->not_dirty = 1;
	aux = str;
	while (aux)
	{
		printf("x = %i; y = %i; Dirty: %i\n", aux->x, aux->y, aux->not_dirty);
		aux = aux->next;
	}
	printf("---\n");
	clean_dirty_collision_tiles(&str);
	aux = str;
	while (aux)
	{
		printf("x = %i; y = %i; Dirty: %i\n", aux->x, aux->y, aux->not_dirty);
		aux = aux->next;
	}
}
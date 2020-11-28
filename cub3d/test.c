/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:16:58 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/28 14:07:47 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int main (void)
{
	t_list *list = 0;
	int i = 0;
	int *nb;

	while (i < 4)
	{
		nb = malloc(sizeof(int));
		*nb = i;
		ft_lstadd_back(&list, ft_lstnew(nb));
		i++;
	}

	while (list)
	{
		if (*(int *)list->content == 2)
			ft_lstmove_backwards(list);
		printf("%i\n", *(int *)list->content);
		list = list->next;
	}
}
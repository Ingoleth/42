/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmove_forwards.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:21:25 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/28 13:22:09 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmove_forwards(t_list *list, t_list *src)
{
	void *aux;

	if (list == src)
		return ;
	while (src->next->content != list->content && src)
		src = src->next;
	if (!src)
		return ;
	aux = src->content;
	src->content = list->content;
	list->content = aux;
}

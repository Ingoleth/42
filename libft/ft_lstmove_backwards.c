/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmove_backwards.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:22:23 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/28 13:22:49 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmove_backwards(t_list *list)
{
	void *aux;

	if (list->next)
	{
		aux = list->content;
		list->content = list->next->content;
		list->next->content = aux;
	}
}

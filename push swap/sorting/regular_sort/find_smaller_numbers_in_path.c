/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smaller_numbers_in_path.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:12:26 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/07 17:41:30 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks wheter the next smaller number found is within the current index and
** the targeted destination.
** 
** Note that the first elements of the linked list has three elements instead of
** two, where [0] is the location of the smaller number found and [2] is the
** destination
*/

static t_bool	is_number_within_indexes(t_list *smaller_num, int index)
{
	if
	(
		(((int *)smaller_num->content)[0] < index
		&&
		index < ((int *)smaller_num->content)[2])
		||
		(((int *)smaller_num->content)[2] < index
		&&
		index < ((int *)smaller_num->content)[0])
	)
		return (true);
	else
		return (false);
}

/*
** If the index of the found number is within the first
** found number and the destination, the index and the value are
** stored in the list and true is returned;
** 
** Otherwise, false is returned, which stops recursion in the
** super function.
*/

static t_bool	add_number_to_list(t_list **smaller_num, int index, int value)
{
	t_list	*aux;

	if (is_number_within_indexes(smaller_num[0], index))
	{
		ft_lstdbl_add_back(smaller_num, ft_lstnew(ft_calloc(2, sizeof(int))));
		aux = ft_lstlast(smaller_num[0]);
		if (aux == NULL || aux->content == NULL)
			return ;
		((int *)aux->content)[0] = index;
		((int *)aux->content)[1] = value;
	}
	else
		return (false);
	return (true);
}

/*
** Finds and lists the smaller numbers found in the path to the destination
** (biggest number in the array, which will be pushed to b);
** The path to destination will be determined by the position
** of the immediately smaller number to destination found in the array
** 
** If (recursively) the next smaller number is in the path, it gets added to the list.
*/

void	find_smaller_numbers_in_path(t_array_info *arrays, t_list **smaller_num,
	int previous_num, int previous_index)
{
	int		index;
	t_list	*aux;

	index = find_bigger_num(arrays, &previous_num, true, previous_num);
	if (index == previous_index)
		return ;
	if (*smaller_num == NULL)
	{
		ft_lstdbl_add_back(smaller_num, ft_lstnew(ft_calloc(3, sizeof(int))));
		if (smaller_num[0] == NULL || smaller_num[0]->content == NULL)
			return ;
		((int *)smaller_num[0]->content)[0] = index;
		((int *)smaller_num[0]->content)[1] = previous_num;
		((int *)smaller_num[0]->content)[2] = previous_index;
	}
	else if (!add_number_to_list(smaller_num, index, previous_index))
		return ;
	find_smaller_number_in_path(arrays, smaller_num, previous_num, index);
}

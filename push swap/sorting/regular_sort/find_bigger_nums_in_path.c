/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bigger_nums_in_path.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:12:26 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/12 20:43:53 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks wheter the next smaller number found is within the current index and
** the targeted destination.
** 
** Note that the first elements of the linked list has three elements instead of
** two, where [0] is the location of the smaller number found and [2] is the
** destination.
**
** Additionally, in order to add the number to the list, the number and the
** destination need to be 2 spaces apart (which are the needeed instructions to
** move it in place on the list);
*/

static t_bool	is_number_within_indexes(t_list *smaller_num, int index)
{
	int	bigger_num_index;
	int	first_num_index;
	
	bigger_num_index = ((int *)smaller_num->content)[2];
	smaller_num = ft_lstlast(smaller_num);
	first_num_index = ((int *)smaller_num->content)[0];
	printf("Checking number at index %i; Bigger_num = %i; first_num = %i\n", index, bigger_num_index, first_num_index);
	if (first_num_index < index && index < bigger_num_index)
		return(true);
	else if (bigger_num_index < index && index < first_num_index)
		return (true);
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
		ft_lstadd_back(smaller_num, ft_lstnew(ft_calloc(2, sizeof(int))));
		aux = ft_lstlast(smaller_num[0]);
		if (aux->content == NULL)
		{
			aux = *smaller_num;
			while (aux->next->next)
				aux = aux->next;
			aux->next = 0;
			return (false);
		}
		((int *)aux->content)[0] = index;
		((int *)aux->content)[1] = value;
	}
	else
		return (false);
	return (true);
}

/*
** Finds and lists the bigger numbers found in the path to the destination
** (smallest number in the array, which will be pushed to b);
** The path to destination will be determined by the position
** of the immediately bigger number to destination found in the array
** 
** If (recursively) the next bigger number is in the path, it gets added to the list.
*/

void	find_bigger_nums_in_path(t_array_info *arrays, t_list **smaller_num,
	int previous_num, int previous_index)
{
	int		index;

	index = find_bigger_num(arrays, &previous_num, true, previous_num);
	if (*smaller_num == NULL)
	{
		ft_lstadd_back(smaller_num, ft_lstnew(ft_calloc(3, sizeof(int))));
		if (smaller_num[0] == NULL)
			return ;
		if (smaller_num[0]->content == NULL)
		{
			free(smaller_num);
			*smaller_num = 0;
			return ;
		}
		((int *)smaller_num[0]->content)[0] = index;
		((int *)smaller_num[0]->content)[1] = previous_num;
		((int *)smaller_num[0]->content)[2] = previous_index;
	}
	else 
	{
		if (smaller_num[0] && index == previous_index)
			return ;
		if (!add_number_to_list(smaller_num, index, arrays->array_a[index]))
		return ;
	}
	find_bigger_nums_in_path(arrays, smaller_num, previous_num, index);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:36:59 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/07 17:12:15 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	check_route_right(int destination, t_list *smaller_num,
	int array_lenght)
{
	int	route_swapping_smaller_nums;
	int	alternate_route;
	int i;

	alternate_route = array_lenght - destination + ft_lstsize(smaller_num) * 2;
	route_swapping_smaller_nums = ((int *)smaller_num->content)[0] - 1;
	while (smaller_num->next)
	{
		i = ((int *)smaller_num->content)[0];
		smaller_num = smaller_num->next;
		route_swapping_smaller_nums += i - ((int *)smaller_num->content)[0];
	}
	if (alternate_route > route_swapping_smaller_nums)
		return (true);
	else
		return (false);
}

static t_bool	check_route_left(int destination, t_list *smaller_num,
	int array_lenght)
{
	int	route_swapping_smaller_nums;
	int	alternate_route;
	int i;

	alternate_route = destination + ft_lstsize(smaller_num) * 2;
	route_swapping_smaller_nums = array_lenght - ((int *)smaller_num->content)[0];
	while (smaller_num->next)
	{
		i = ((int *)smaller_num->content)[0];
		smaller_num = smaller_num->next;
		route_swapping_smaller_nums += ((int *)smaller_num->content)[0] - i - 1;
	}
	if (alternate_route > route_swapping_smaller_nums)
		return (true);
	else
		return (false);
}

void	move_bigger_num_to_b(t_array_info *arrays)
{
	int	destination;
	int	bigger_num;
	t_list *smaller_num;
	
	smaller_num = NULL;
	destination = find_bigger_num(arrays, &bigger_num, false, 0);
	find_smaller_nums_in_path(arrays, &smaller_num, bigger_num, destination);
	if (smaller_num)
	{
		if (((int *)smaller_num->content)[0] < destination)
		{
			if (check_route_left(destination, smaller_num, arrays->array_a_length))
			{
				printf("I've taken this route!\n"); //If null, do nothing!
				destination -= ft_lstsize(smaller_num);
			}
		}
		else
		{
			if (check_route_right(destination, smaller_num, arrays->array_a_length))
				printf("I've taken this route!\n"); //If null, do nothing!
		}
	}
	move_to_index(arrays, get_offset(arrays, destination));
	instruction(push_b, arrays);
	if (smaller_num)
		ft_lstclear(&smaller_num, free);
}

void	regular_sort(t_array_info *arrays)
{
	if (!is_sorted(arrays->array_a, arrays->array_a_length, ascending))
	{
		while (arrays->array_a_length > 5)
			move_bigger_num_to_b(arrays);
		sort_5_over_stack(arrays, array_a);
		while (arrays->array_b_length)
			instruction(push_a, arrays);
	}
}

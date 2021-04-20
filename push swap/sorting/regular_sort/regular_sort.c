/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:36:59 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/13 20:13:35 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	check_route_left(int destination, t_list *smaller_num,
	int array_lenght)
{
	int	route_swapping_smaller_nums;
	int	alternate_route;
	int i;

	route_swapping_smaller_nums = array_lenght - destination + ft_lstsize(smaller_num) * 2;
	alternate_route = ((int *)smaller_num->content)[0] - 1;
	while (smaller_num->next)
	{
		i = ((int *)smaller_num->content)[0];
		smaller_num = smaller_num->next;
		alternate_route += i - ((int *)smaller_num->content)[0];
	}
	if (alternate_route > route_swapping_smaller_nums)
		return (true);
	else
		return (false);
}

static t_bool	check_route_right(int destination, t_list *smaller_num,
	int array_lenght)
{
	int	route_swapping_smaller_nums;
	int	alternate_route;
	int i;

	alternate_route = array_lenght - ((int *)smaller_num->content)[0];
	route_swapping_smaller_nums = destination + ft_lstsize(smaller_num) * 2;
	while (smaller_num->next)
	{
		i = ((int *)smaller_num->content)[0];
		smaller_num = smaller_num->next;
		alternate_route += ((int *)smaller_num->content)[0] - i - 1;
	}
	printf("Alternate route = %i; route swapping smaller nums = %i\n", alternate_route, route_swapping_smaller_nums);
	if (alternate_route > route_swapping_smaller_nums)
		return (true);
	else
		return (false);
}

void	move_smaller_num_to_b(t_array_info *arrays)
{
	int	destination;
	int	aux;
	t_list *next_smaller_num;
	
	next_smaller_num = NULL;
	destination = find_smallest_num(arrays, &aux, false, 0);
	find_smallest_nums_in_path(arrays, &next_smaller_num, aux, destination);
	if (next_smaller_num)
	{
		print_smaller_nums_found(next_smaller_num);
		if (((int *)next_smaller_num->content)[0] < destination)
		{
			if (check_route_right(destination, next_smaller_num, arrays->array_a_length))
				push_smaller_numbers(arrays, next_smaller_num, right);
		}
		else
		{
			if (check_route_left(destination, next_smaller_num, arrays->array_a_length))
				push_smaller_numbers(arrays, next_smaller_num, left);
		}
	}
	push_num(arrays, array_b, smaller);
	while (arrays->array_b[arrays->array_b_length - 1] > arrays->array_b[0])
		instruction(rev_rot_b, arrays);
	if (next_smaller_num)
		ft_lstclear(&next_smaller_num, free);
}

void	regular_sort(t_array_info *arrays)
{
	while (arrays->array_a_length > 5
		&& !is_sorted(arrays->array_a, arrays->array_a_length, ascending))
		move_smaller_num_to_b(arrays);
	sort_5(arrays);
	while (arrays->array_b_length)
		instruction(push_a, arrays);
}

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

void	move_bigger_num_to_b(t_array_info *arrays)
{
	int	destination;
	int	bigger_num;
	int number_of_steps;
	t_list *smaller_num;
	
	smaller_num = NULL;
	destination = find_bigger_num(arrays, &bigger_num, false, 0);
	find_smaller_nums_in_path(arrays, &smaller_num, bigger_num, destination);
	if (((int *)smaller_num->content)[0] < destination)
	{
		number_of_steps = destination + 2 * ft_lstsize(smaller_num);
		if (number_of_steps < arrays->array_a_length - destination)
			printf("I've taken this route!\n"); //If null, do nothing!
		else
			printf("I've taken this other route!\n");
	}
	else
	{
		number_of_steps = arrays->array_a_length - destination + 2 * ft_lstsize(smaller_num);
		if (number_of_steps < destination)
			move_smaller_numbers_to_b(arrays, smaller_num, &destination);
	}
	move_num_to_b(destination);
	if (smaller_num)
		free(smaller_num);
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

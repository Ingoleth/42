/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:39:14 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/07 17:06:36 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    store_values_to_swap(t_array_info *arrays, int start, int end)
{
    if (start == end)
        return ;
    if (end == arrays->array_a_length - 1 && start == 0)
    {
        move_to_index(arrays, end);
        instruction(swap_a, arrays);
        return ;
        
    }
    move_to_index(arrays, start);
    if (start + 1 == end)
    {
        instruction(swap_a, arrays);
        return ;
    }
    instruction(push_b, arrays);
    move_to_index(arrays, end - 1);
    instruction(push_b, arrays);
	move_to_index(arrays, end - 1);
    instruction(rot_b, arrays);
    instruction(push_a, arrays);
    move_to_index(arrays, start);
    instruction(push_a, arrays);
    if (start == 0)
        arrays->current_index = 0;
}

int get_pivot_point(t_array_info *arrays, int start, int end)
{
    int pivot;
    int up;
    int down;

    up = end;
    down = start;
    pivot = arrays->array_a[get_offset(arrays, start)];
    while (down < up)
    {
        while (arrays->array_a[get_offset(arrays, down)] <= pivot && down < end)
            down++;
        while (arrays->array_a[get_offset(arrays, up)] > pivot)
            up--;
        if (down < up)
            store_values_to_swap(arrays, down, up);
    }
    store_values_to_swap(arrays, start, up);
    return (up);
}

void	quick_sort(t_array_info *arrays, int start, int end)
{
    int pivot_point;

    if (start < end)
    {
        pivot_point = get_pivot_point(arrays, start, end);
        quick_sort(arrays, start, pivot_point - 1);
        quick_sort(arrays, pivot_point + 1, end);
    }
}

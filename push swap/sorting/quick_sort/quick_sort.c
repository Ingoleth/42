/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:39:14 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/05 12:42:32 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    store_values_to_swap(t_array_info *arrays, int start, int end)
{
    printf("Value left (at %i) = %i; Value right (at %i) = %i;", start, arrays->array_a[start], end, arrays->array_a[end]);
    move_to_index(arrays, start);
    instruction(push_b, arrays);
    print_stacks(arrays);
    move_to_index(arrays, end);
    instruction(push_b, arrays);
    print_stacks(arrays);
    instruction(rot_b, arrays);
    instruction(push_a, arrays);
    print_stacks(arrays);
    move_to_index(arrays, start);
    instruction(push_a, arrays);
    print_stacks(arrays);
    exit(0);
}

int     get_pivot_point(t_array_info *arrays, int start, int end)
{
    int pivot;
    int up;
    int down;

    up = end;
    down = start;
    pivot = arrays->array_a[start];
    while (down < up)
    {
        while (arrays->array_a[down] <= pivot && down < end)
            down++;
        while (arrays->array_a[up] > pivot)
            up--;
        if (down < up)
            store_values_to_swap(arrays, down, up);
    }
    arrays->array_a[start] = arrays->array_a[up];
    arrays->array_a[up] = pivot;
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

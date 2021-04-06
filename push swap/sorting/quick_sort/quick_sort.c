/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:39:14 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/06 14:05:26 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    store_values_to_swap(t_array_info *arrays, int start, int end)
{
    move_to_index(arrays, start);
    instruction(push_b, arrays);
	print_stacks(arrays);
    move_to_index(arrays, end);
	print_stacks(arrays);
    instruction(push_b, arrays);
	move_to_index(arrays, end);
    instruction(rot_b, arrays);
    instruction(push_a, arrays);
    move_to_index(arrays, start - 1);
    instruction(push_a, arrays);
	printf("\n-----------\nDid a swap!\n-----------\n");
}

void	swap_num(int *array, int down, int up)
{
	int temp;

	printf("I want to swap %d (at array[%d]) with %d (at array [%d])\n", array[down], down, array[up], up);
	temp = array[down];
	array[down] = array[up];
	array[up] = temp;
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
			swap_num(arrays->array_a, down, up);
            //store_values_to_swap(arrays, down, up);
    }
	printf("No more swaps to do!\n");
	//store_values_to_swap(arrays, start, up);
	printf("I want to swap %d (at array[%d]) with %d (at array [%d])\n", arrays->array_a[start], start, arrays->array_a[up], up);
    arrays->array_a[start] = arrays->array_a[up];
	arrays->array_a[up] = pivot;
    return (up);
}

void	quick_sort(t_array_info *arrays, int start, int end)
{
    int pivot_point;

	store_values_to_swap(arrays, 2, 4);
	move_to_index(arrays, 0);
	print_stacks(arrays);
	exit(0);
    if (start < end)
    {
        pivot_point = get_pivot_point(arrays, start, end);
        quick_sort(arrays, start, pivot_point - 1);
        quick_sort(arrays, pivot_point + 1, end);
    }
}

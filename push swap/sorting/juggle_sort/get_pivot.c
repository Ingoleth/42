/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:13:05 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/25 12:34:01 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_pivot(int *array, int start, int end)
{
    int swaps;
    int index;
    int pivot;
    int mean_num_of_swaps;
    int i;

    index = start;
    mean_num_of_swaps = ((end - start) / 2);
    swaps = 0;
    pivot = array[start];
    while (swaps != mean_num_of_swaps)
    {
        pivot = array[index];
        swaps = 0;
        i = start;
        while (i < end)
        {
            if (array[i] <= pivot)
                swaps++;
            i++;
        }
            swaps = end - start - swaps;
        if (swaps < 0)
            swaps *= -1;
        index++;
    }
    return (pivot);
}
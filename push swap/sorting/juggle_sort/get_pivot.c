#include "push_swap.h"

int get_pivot(int *array, int start, int end)
{
    int swaps;
    int index;
    int pivot;
    int mean_num_of_swaps;
    int i;

    index = start;
    mean_num_of_swaps = (end - start / 2);
    swaps = 0;
    pivot = array[start];
    while (swaps != mean_num_of_swaps)
    {
        pivot = array[index];
        swaps = 0;
        i = start;
        while (start < end)
        {
            if (array[start] <= pivot)
                swaps++;
            start++;
        }
            swaps = end - start - swaps;
        if (swaps < 0)
            swaps *= -1;
        index++;
    }
    return (pivot);
}
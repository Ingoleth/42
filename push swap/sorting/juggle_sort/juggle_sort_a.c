
#include "push_swap.h"

void    sort_remaining_numbers(t_array_info *arrays, int length)
{
    int smaller_num_index;
    if (length < 2 || is_sorted(arrays->array_a, length, descending))
        return ;
    else if (length == 2)
        instruction(swap_a, arrays);
    else
    {
        smaller_num_index = find_smallest_num(arrays, 0, false, 0);
        if (smaller_num_index == 1)
            instruction(swap_a, arrays);
        if (arrays->array_a[1] > arrays->array_a[0]
            && arrays->array_a[1] > arrays->array_a[2] )
        {
            instruction(push_b, arrays);
            instruction(swap_a, arrays);
            instruction(push_a, arrays);
        }
        if (smaller_num_index != 1)
        {
            instruction(swap_a, arrays);
            if (arrays->array_a[1] > arrays->array_a[2])
            {
                instruction(push_b, arrays);
                instruction(swap_a, arrays);
                instruction(push_a, arrays);
            }
        }
    }
}

static int push_and_rotate_backwards(t_array_info *arrays, int *nb_swaps, int i)
{
    int pivot;

    pivot = get_pivot(arrays->array_a, arrays->sorted_elements_a, arrays->array_a_length);
    while (i)
    {
        instruction(rot_a, arrays);
        i--;
        if (arrays->array_a[0] <= pivot)
        {
            instruction(push_b, arrays);
            *nb_swaps += 1;
        }
    }
    return (i);
}

static int push_and_rotate_forwards(t_array_info *arrays, int *nb_swaps, int i)
{
    int pivot;

    pivot = get_pivot(arrays, 0, arrays->array_a_length - arrays->sorted_elements_a);
    while (i < arrays->array_a_length - arrays->sorted_elements_a)
    {
        if (arrays->array_a[0] <= pivot)
        {
            instruction(push_b, arrays);
            *nb_swaps += 1;
        }
        else
        {
            instruction(rot_a, arrays);
            i++;
        }
    }
    return (i);
}

void    juggle_sort_a(t_array_info *arrays)
{
    int pivot;
    int i;
    unsigned long int nb_swaps;
    t_list *subdivisions;

    i = 0;
    subdivisions = NULL;
    while (arrays->array_a_length > arrays->sorted_elements_a + 5)
    {
        nb_swaps = 0;
        if (i == 0)
            i = push_and_rotate_forwards(arrays, &nb_swaps, i);
        else
            i = push_and_rotate_backwards(arrays, &nb_swaps, i);
        if (nb_swaps)
            ft_lstadd_front(&subdivisions, ft_lstnew((void *)nb_swaps));
    }
    sort_5_over_stack(arrays, array_a);
    arrays->sorted_elements_a += arrays->array_a_length - arrays->sorted_elements_a;
    juggle_sort_b(arrays, subdivisions);
}

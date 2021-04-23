#include "push_swap.h"

void push_remaining_elements_to_a()
{
    return ;
}

static int push_and_rotate_forwards(t_array_info *arrays, int *current_set_size, int i)
{
    int pivot;

    pivot = get_pivot(arrays->array_b, 0, *current_set_size);
    while (i < current_set_size)
    {
        if (arrays->array_b[0] >= pivot)
        {
            instruction(push_a, arrays);
            *current_set_size -= 1; 
        }
        else
        {
            instruction(rot_b, arrays);
            i++;
        }
    }
    return (i);
}

static int push_and_rotate_backwards(t_array_info *arrays, int *current_set_size, int i)
{
    int pivot;

    pivot = get_pivot(arrays->array_b, arrays->array_b_length - *current_set_size, arrays->array_b_length);
    while (i)
    {
        instruction(rev_rot_b, arrays);
        i--;
        if (arrays->array_b[0] >= pivot)
        {
            instruction(push_a, arrays);
            *current_set_size -= 1;
        }
    }
    return (i);
}

void    juggle_sort_b(t_array_info* arrays, t_list *subdivisions)
{
    t_list *aux;
    int i;
    int current_set_size;

    while (subdivisions)
    {
        current_set_size = (int)subdivisions->content;
        i = 0;
        while (current_set_size > 5)
        {
            if (i == 0)
                i = push_and_rotate_forwards(arrays, &current_set_size, i);
            else
                i = push_and_rotate_backwards(arrays, &current_set_size, i);
        }
        juggle_sort_a(arrays);
        push_remaining_elements_to_a(arrays, current_set_size);
        aux = subdivisions;
        subdivisions = subdivisions->next;
        ft_lstdelone(aux, 0);
    }
}
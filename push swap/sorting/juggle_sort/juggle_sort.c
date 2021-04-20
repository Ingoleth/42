
#include "push_swap.h"

int get_median(t_array_info *arrays, int stack)
{
    if (stack == array_a)
        return (arrays->array_a[
            (arrays->array_a_length - arrays->sorted_elements_a) / 2]);
    else
        return (arrays->array_b[
            (arrays->array_b_length - arrays->sorted_elements_b) / 2]);
}

void    juggle_sort_on_b(t_array_info *arrays)
{
    int median;
    int i;
    unsigned long int chunk_size;

    while (arrays->array_a_length > arrays->sorted_elements_a + 5)
    {
        median = get_median(arrays, array_a);
        i = 0;
        chunk_size = 0;
        while (i < arrays->array_a_length - arrays->sorted_elements_a)
        {
            if (arrays->array_a[0] <= median)
            {
                instruction(push_b, arrays);
                chunk_size++;
            }
            else
            {
                instruction(rot_a, arrays);
                i++;
            }
        }
        if (chunk_size)
            ft_lstadd_front(&arrays->subdivisions_on_b, ft_lstnew((void *)chunk_size));
    }
    sort_5_over_stack(arrays, array_a);
    arrays->sorted_elements_a += arrays->array_a_length - arrays->sorted_elements_a;
}

void    juggle_sort_on_a(t_array_info *arrays)
{
    int median;
    int i;

    while (arrays->array_a_length > arrays->sorted_elements_a + 5)
    {
        median = get_median(arrays, array_a);
        while (i < arrays->array_a_length - arrays->sorted_elements_a)
        {
            if (arrays->array_a[0] < median)
                instruction(push_b, arrays);
            else
            {
                instruction(rot_a, arrays);
                i++;
            }
        }
    }
    sort_5_over_stack(arrays, array_a);
    arrays->sorted_elements_a += arrays->array_a_length - arrays->sorted_elements_a;
    print_stacks(arrays);
}


#include "push_swap.h"

void push_remaining_elements_to_a(t_array_info *arrays, int current_set_size)
{
    int i;

    i = 0;
    while (i < current_set_size)
    {
        if (arrays->array_b[0] > arrays->array_b[1])
            instruction(push_a, arrays);
        else if (arrays->array_a[0] > arrays->array_b[1])
            instruction(swap_a_and_b, arrays);
        else
            instruction(swap_b, arrays);
    }
    
    while (current_set_size--)
        instruction(push_a, arrays);
}
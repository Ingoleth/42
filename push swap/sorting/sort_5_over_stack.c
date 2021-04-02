/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:48:00 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/01 21:23:08 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_over_stack(t_array_info *arrays, int fd, int stack)
{
    int i;

    i = 2;
    if (stack == array_a)
    {
        while (i--)
            push_num(arrays, fd, array_b, smaller);
        sort_3_over_stack(arrays, fd, array_a);
        instruction(push_a, fd, arrays);
	    instruction(push_a, fd, arrays);
    }
    else
    {
        print_stacks(arrays);
        while (i--)
            push_num(arrays, fd, array_a, bigger);
        print_stacks(arrays);
        printf("Sort 3 starts here!\n");
        sort_3_over_stack(arrays, fd, array_b);
        print_stacks(arrays);
        printf("Sort 3 ends here!\n");
        instruction(push_b, fd, arrays);
	    instruction(push_b, fd, arrays);
    }
}
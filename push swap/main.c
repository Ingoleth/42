/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:22:26 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 02:02:50 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
    int *array_a;
    int *array_b;
    int length;
    t_flags flags;
    
    if (argc == 1)
        return (0);
    array_a = handle_input(argc, argv, &flags);
    length = get_array_length(array_a);
    array_b = ft_calloc(length + 1, sizeof(int));
    if (array_b == NULL)
    {
        free(array_a);
        return (1);
    }
    //array_b = get_rand_array(3, 16);
    if (flags.verbose)
        print_stacks(array_a, array_b);
    if (is_sorted(array_a))
        printf("Array is sorted!\n");
    else
        printf("Array is not sorted!\n");
    free(array_a);
    free(array_b);
}
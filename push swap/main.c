/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:22:26 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/29 14:22:47 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
    int *array;
    int i;
    t_flags flags;
    
    array = handle_input(argc, argv, &flags);
    i = 0;
    while (array[i])
    {
        printf("* %d\n", array[i]);
        i++;
    }
    free(array);
}
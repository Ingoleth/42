/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rand_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:48:50 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/29 15:47:22 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_power(int root, int exp)
{
    if (exp <= 0)
        return (1);
    return (root *  ft_power(root, exp - 1));
}

int rand_num(unsigned short *lfsr, unsigned int *bit, int length)
{
    int nb;

    if (length > 5)
        length = 0;
    if (length < 1)
        length = 1;
    length = ft_power(10, length);
    *bit  = ((*lfsr >> 0) ^ (*lfsr >> 2) ^ (*lfsr >> 3) ^ (*lfsr >> 5) ) & 1;
    *lfsr =  (*lfsr >> 1) | (*bit << 15);
    nb = *lfsr;
    while (nb > length)
        nb /= 10;
    return (nb);
  }

int *get_rand_array(int length, unsigned short lfsr)
{
    int *array;
    int i;
    int nb_length;
    unsigned bit;

    array = ft_calloc(length, sizeof(int));
    if (array == NULL)
        return (NULL);
    i = 0;
    while (i < length)
    {
        nb_length = 6;
        while (nb_length > 5)
            nb_length = rand_num(&lfsr, &bit, 1);
        if (!is_repeated_array(nb_length, array))
        {
            array[i] = rand_num(&lfsr, &bit, nb_length);
            nb_length = rand_num(&lfsr, &bit, 1);
            if (nb_length % 2)
                array[i] *= -1;
            i++;
        }
    }
    return (array);
}
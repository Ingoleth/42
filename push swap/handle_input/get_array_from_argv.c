/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_from_argv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:46:11 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/29 13:47:47 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool is_repeated_array(int nb, int *array)
{
    int i = 0;

    while (array[i])
    {
        if (nb == array[i])
            return (true);
        i++;
    }
    return (false);
}

int *get_array_from_argv(char **argv)
{
    int size;
    int *aux;
    int nb;

    size = 0;
    while (argv[size])
    {
        if (!is_number(argv[size]) || is_long_int(argv[size]))
        {
            ft_putstr_fd("Error\n", STDERR_FILENO);
            exit(1);
        }
        size++;
    }
    if (size == 0)
    {
            ft_putstr_fd("Error\n", STDERR_FILENO);
        exit(1);
    }
    size = 0;
    aux = ft_calloc(size, sizeof(int));
    if (aux == NULL)
    {
        ft_putstr_fd("Error\n", STDERR_FILENO);
        exit(1);
    }    
    while (argv[size])
    {
        nb = ft_atoi(argv[size]);
        if (is_repeated_array(nb, aux))
        {
            free(aux);
            ft_putstr_fd("Error\n", STDERR_FILENO);
            exit(1);
        }
        aux[size] = nb;
        size++;
    }
    return (aux);
}
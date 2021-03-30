/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:39:13 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 02:02:35 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** TODO: Make the conditional_flag_detection more flexible...
*/

void    handle_function_flags(char ***argv, t_flags  *flags)
{
    while (argv[0][0] &&
    (!ft_strncmp(argv[0][0], "-v", 3) || !ft_strncmp(argv[0][0], "-c", 3)))
    {
        if (!ft_strncmp(argv[0][0], "-v", 3))
        {
            if (flags->verbose == true)
            {
                ft_putstr_fd("Error", STDERR_FILENO);
                exit(1);
            }
            flags->verbose = true;
        }
        else if (!ft_strncmp(argv[0][0], "-c", 3))
        {
            if (flags->colour == true)
            {
                ft_putstr_fd("Error", STDERR_FILENO);
                exit(1);
            }
            flags->colour = true;
        }
        *argv = *argv + 1;
    } 
}

void    handle_flags(char ***argv, t_flags  *flags)
{
    ft_memset(flags, 0, sizeof(t_flags));
    if (!ft_strncmp(argv[0][0], "-ci", 4))
        flags->mode_input = true;
    else if (!ft_strncmp(argv[0][0], "-fi", 4))
        flags->mode_fd = true;
    else if (!ft_strncmp(argv[0][0], "-ra", 4))
        flags->mode_rand = true;
    else
        flags->mode_argv = true;
    if (!flags->mode_argv)
        *argv = *argv + 1;
    handle_function_flags(argv, flags);
    if (!flags->mode_input && !argv[0][0])
    {
        if (flags->mode_argv)
            exit(0);
        ft_putstr_fd("Error\n", STDERR_FILENO);
        exit(1);
    }
}

int *handle_input(int argc, char **argv, t_flags  *flags)
{
    int *array;
    int fd;

    if (argc == 1)
        return (0);
    argv++;
    handle_flags(&argv, flags);
    if (flags->mode_input)
        array = get_input_array(STDIN_FILENO);
    else if (flags->mode_fd)
    {
        fd = open(argv[0], O_RDONLY);
        if (fd == -1)
        {
            printf("Couldn't open input file!\n");
            exit(1);
        }
        array = get_input_array(fd);
        close(fd);
    }
    else if (flags->mode_rand)
        array = get_rand_array(ft_atoi(argv[0]), ft_atoi(argv[1]));
    else
        array = get_array_from_argv(argv);
    return (array);
}

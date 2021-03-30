/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:39:13 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 15:27:10 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *handle_random_input(char **argv, t_bool verbose)
{
    if (argv[0] && argv[1])
    {
        if (verbose)
        {
            if (!ft_atoi(argv[0]))
                ft_printf(STDERR_FILENO, "Array lenght can't be zero!\n");
            else if (!is_number(argv[1]))
                ft_printf(STDERR_FILENO, "Array seed must be numeric!\n");
        }
        else
            return(get_rand_array(ft_atoi(argv[0]), ft_atoi(argv[1])));
    }
    if (verbose)
    {
        if (!argv[0])
            ft_printf(STDERR_FILENO, "Error: array lenght and seed missing!\n");
        else
            ft_printf(STDERR_FILENO, "Error: random seed missing!\n");
    }
    exit(-1);
}

int *handle_fd_array(char **argv, t_bool verbose)
{
    int fd;
    int *array;

    fd = open(argv[0], O_RDONLY);
    if (fd == -1)
    {
        if(argv[0])
        {
            if (verbose)
                ft_printf(STDERR_FILENO, "Couldn't open input file!\n");
            else
                ft_printf(STDERR_FILENO, "KO\n");
        }
        exit(1);
    }
    array = get_input_array(fd);
    close(fd);
    return (array);
}

int *handle_input(int argc, char **argv, t_flags  *flags)
{
    int *array;

    if (argc == 1)
        return (0);
    argv++;
    handle_flags(&argv, flags);
    if (flags->mode_input)
        array = get_input_array(STDIN_FILENO);
    else if (flags->mode_fd)
        array = handle_fd_array(argv, flags->verbose);
    else if (flags->mode_rand)
        array = handle_random_input(argv, flags->verbose);
    else
        array = get_array_from_argv(argv);
    return (array);
}

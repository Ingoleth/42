/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:57:16 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 15:20:02 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_error_and_exit(char **flags_list, t_flags *flags, char ***argv)
{
    free(flags_list);
    if (flags->mode_argv && !argv[0][0])
        exit(0);
    ft_putstr_fd("Error\n", STDERR_FILENO);
        exit(1);
}

void    handle_input_flags(char **flags_list, char ***argv, t_flags  *flags)
{
     if (!ft_strncmp(argv[0][0], "-ci", 4))
    {
        if (flags->mode_input || flags->mode_fd || flags->mode_rand)
            print_error_and_exit(flags_list, flags, argv);
        flags->mode_input = true;
    }
    else if (!ft_strncmp(argv[0][0], "-fi", 4))
    {
        if (flags->mode_input || flags->mode_fd || flags->mode_rand)
            print_error_and_exit(flags_list, flags, argv);
        flags->mode_fd = true;
    }
    else if (!ft_strncmp(argv[0][0], "-ra", 4))
    {
        if (flags->mode_input || flags->mode_fd || flags->mode_rand)
            print_error_and_exit(flags_list, flags, argv);
        flags->mode_rand = true;
    }
    else if (!ft_strncmp(argv[0][0], "-ifi", 5))
    {
        if (flags->inst_mode_fd)
            print_error_and_exit(flags_list, flags, argv);
        flags->inst_mode_fd = true;
    }
}

static t_bool check_flags(char **flags_list, char *str)
{
    int i;
    int lenght;

    i = 0;
    lenght = ft_strlen(str) + 1;
    while (flags_list[i])
    {
        if (!ft_strncmp(str, flags_list[i], lenght))
            return (true);
        i++;
    }
    return (false);
}

void handle_flags(char ***argv, t_flags  *flags)
{
    char **flags_list;

    flags_list = ft_split("-ci -fi -ra -ifi -v -c", ' ');
    ft_memset(flags, 0, sizeof(t_flags));
    while (argv[0][0] && check_flags(flags_list, argv[0][0]))
    {
        if (!ft_strncmp(argv[0][0], "-v", 3))
        {
            if (flags->verbose == true)
                print_error_and_exit(flags_list, flags, argv);
            flags->verbose = true;
        }
        else if (!ft_strncmp(argv[0][0], "-c", 3))
        {
            if (flags->colour == true)
                print_error_and_exit(flags_list, flags, argv);
            flags->colour = true;
        }
        handle_input_flags(flags_list, argv, flags);
        argv[0] = argv[0] + 1;
    }
    if (!flags->mode_fd && !flags->mode_input && !flags->mode_rand)
        flags->mode_argv = true;
    if (flags->mode_argv && !argv[0][0])
        print_error_and_exit(flags_list, flags, argv);
    free(flags_list);
}
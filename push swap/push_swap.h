/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:39:46 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/29 15:46:44 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef	struct		s_flags
{
    t_bool  mode_rand;
    t_bool  mode_input;
    t_bool  mode_fd;
    t_bool  mode_argv;
    t_bool  verbose;
    t_bool  colour;
}					t_flags;

typedef enum	e_error_code
{
    not_nb = 1,
    repeated,
    max_int,
}	            t_error_code;

/*
** INPUT HANDLING
*/

int     *handle_input(int argc, char **argv, t_flags  *flags);
int     *get_input_array(int fd);
int     *get_rand_array(int length, unsigned short lfsr);
int     *get_array_from_argv(char **argv);
t_bool  is_number(char *line);
t_bool  is_repeated(int nb, t_list *array_list);
t_bool  is_repeated_array(int nb, int *array);
t_bool  is_long_int(char *input);

#endif
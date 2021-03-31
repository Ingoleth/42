/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:39:46 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 12:54:11 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_flags
{
	t_bool	mode_rand;
	t_bool	mode_input;
	t_bool	mode_fd;
	t_bool	mode_argv;
	t_bool	inst_mode_fd;
	t_bool	verbose;
	t_bool	file_output;
	int		index;
}					t_flags;

typedef enum e_instructions
{
	swap_a,
	swap_b,
	swap_a_and_b,
	push_a,
	push_b,
	rot_a,
	rot_b,
	rot_a_and_b,
	rev_rot_a,
	rev_rot_b,
	rev_rot_a_and_b
}				t_instructions;

typedef enum e_error_code
{
	not_nb = 1,
	repeated,
	max_int,
}				t_error_code;

/*
** INPUT HANDLING
*/
int				*handle_input(int argc, char **argv, t_flags *flags);
t_flags			initialize_arrays(int
					argc, char **argv, int **array_a, int **array_b);
int				*get_input_array(int fd);
int				*get_rand_array(int length, unsigned short lfsr);
int				*get_array_from_argv(char **argv);
void			handle_flags(char ***argv, t_flags *flags);
t_bool			is_number(char *line);
t_bool			is_repeated(int nb, t_list *array_list);
t_bool			is_repeated_array(int nb, int *array);
t_bool			is_long_int(char *input);
t_bool			is_sorted(int *array);
/*
** INSTRUCTIONS
*/
void			get_instructions(int *array_a, int *array_b, int fd);
void			get_instructions_verbose(int *array_a, int *array_b, int fd);
void			instruction(unsigned int
					instruction, int fd, int *array_a, int *array_b);
void			push(int *dst, int *src);
void			rev_rotate(int *array);
void			rotate(int *array);
void			swap(int *array);
/*
** SORTING
*/
void			bubble_sort(int *array_a, int *array_b, int fd);
/*
**  UTILS 
*/
void			print_stacks(int *array_a, int *array_b);
unsigned int	get_array_length(int *array);
char			*read_input(int fd);

#endif
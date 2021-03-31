/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:39:46 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 21:09:53 by aiglesia         ###   ########.fr       */
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
}			t_flags;

typedef struct s_array_info
{
	int *array_a;
	int *array_b;
	int array_a_length;
	int array_b_length;
	int max_array_length;
}		t_array_info;

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
void			handle_input(int argc, char **argv, t_flags *flags, t_array_info *arrays);
void			initialize_arrays(int argc, char **argv, t_array_info *arrays, t_flags
					*flags);
void			get_input_array(int fd, t_array_info *arrays, t_bool verbose);
void			get_rand_array(int length, unsigned short lfsr, t_array_info *arrays);
void			get_array_from_argv(char **argv, int argc, int argv_pos,
					t_array_info *arrays);
void			handle_flags(char **argv, t_flags *flags, int *argv_pos);
t_bool			is_number(char *line);
t_bool			is_repeated(int nb, t_list *array_list);
t_bool			is_repeated_array(int nb, int *array, int length);
t_bool			is_long_int(char *input);
t_bool			is_sorted(int *array, int length);
/*
** INSTRUCTIONS
*/
void			get_instructions(t_array_info *arrays, int fd);
void			get_instructions_verbose(t_array_info *arrays, int fd);
void			instruction(unsigned int instruction, int fd, t_array_info *arrays);
void			push(int *dst, int *src, int *dst_length, int *src_length);
void			rev_rotate(int *array, int length);
void			rotate(int *array, int length);
void			swap(int *array, int length);
/*
** SORTING
*/
void			bubble_sort(t_array_info *arrays, int fd);
/*
**  UTILS 
*/
void			print_stacks(t_array_info *arrays);
char			*read_input(int fd);

#endif